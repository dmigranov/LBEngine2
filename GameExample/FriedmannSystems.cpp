#pragma once

#include "main.h"

#include "SphericalMath.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


FriedmannTimer* CreateFriedmannSystems(SphericalDopplerEffect* sphericalEffect, 
    SphericalTransformComponent* cameraTransform, SphericalRenderSystem* renderSystem, InputComponent* inputComponent, double initialObjectRadius, Sound * pSound,
    System** controlSystem, System** visibilitySystem, System** radiusUpdateSystem, 
    System** animationSystem, SelectionSystem** selectionSystem, System** soundSystem)
{
    
    auto timer = new FriedmannTimer(2.3, 0.1, 1./9.);
    double initialSimulationMu = timer->GetMu();

    *selectionSystem = new SelectionSystem(inputComponent, initialObjectRadius);

    *controlSystem = new ActionSystem<InputComponent>([sphericalEffect, timer, selectionSystem]
    (Entity* pEntity, double deltaTime) {
            
            auto pInput = pEntity->GetComponent<InputComponent>();
            auto kbs = pInput->GetKeyboardState();
            auto ms = pInput->GetMouseState();

            if (kbs.D1)
                sphericalEffect->SetMode(true);
            else if (kbs.D2)
                sphericalEffect->SetMode(false);

            if (kbs.Left)
            {
                timer->AddDelta(-deltaTime);
            }
            else if (kbs.Right)
            {
                timer->AddDelta(deltaTime);
            }

            if (kbs.M)
                sphericalEffect->SetVelocityCoefficient(sphericalEffect->GetVelocityCoefficient() + 100000);
            else if (kbs.N)
                sphericalEffect->SetVelocityCoefficient(sphericalEffect->GetVelocityCoefficient() - 100000);

            auto entities = (*selectionSystem)->GetEntities();
            auto objectRadius = 0.1;
            auto radius = SphericalEffect::GetRadius();

            auto selectedEntity = (*selectionSystem)->GetSelectedEntity();
            static bool oldPressedSelectButton = false;
            if (selectedEntity != nullptr)
            {
                auto dopplerComponent = selectedEntity->GetComponent <DopplerComponent>();
                if (ms.rightButton)
                {
                    if (!oldPressedSelectButton)
                    {
                        dopplerComponent->SetSelected(!dopplerComponent->IsSelected());
                    }
                    oldPressedSelectButton = true;
                }
                else
                    oldPressedSelectButton = false;
            }


            static bool oldPressedInvertButton = false;
            if (kbs.I)
            {
                if (!oldPressedInvertButton)
                    for (auto pEntity : entities)
                    {
                        auto dopplerComponent = pEntity->GetComponent <DopplerComponent>();
                        dopplerComponent->SetSelected(!dopplerComponent->IsSelected());
                    }
                oldPressedInvertButton = true;
            }
            else
                oldPressedInvertButton = false;


            if (kbs.V)
            {
                //todo: ������: �������� �� ��������� ����� (������ - ���)?
                for (auto pEntity : entities)
                {
                    auto dopplerComponent = pEntity->GetComponent <DopplerComponent>();
                    if (dopplerComponent->IsSelected())
                    {
                        pEntity->SetVisible(false);
                        dopplerComponent->SetSelected(false);
                    }
                } 
            }


            static bool oldPressedTextureButton = false;
            if (kbs.T)
            {
                if (!oldPressedTextureButton)
                    for (auto pEntity : entities)
                    {
                        auto dopplerComp = pEntity->GetComponent<DopplerComponent>();
                        if (dopplerComp->IsSelected())
                        {
                            dopplerComp->SetAlternativeTexture(!dopplerComp->IsAlternativeTexture());
                        }
                    }
                oldPressedTextureButton = true;
            }
            else
                oldPressedTextureButton = false;


            if (kbs.R) //revert
                for (auto pEntity : entities)
                {
                    auto dopplerComponent = pEntity->GetComponent <DopplerComponent>();
                    dopplerComponent->SetSelected(false);
                    dopplerComponent->SetAlternativeTexture(false);
                    pEntity->SetVisible(true);
                }
        });

    *visibilitySystem = new ActionSystem<SphericalTransformComponent, SphericalRenderingComponent>([sphericalEffect, cameraTransform, timer]
    (Entity* pEntity, double deltaTime) {
            auto cameraPos = cameraTransform->GetSphericalPosition();

            auto pTransform = pEntity->GetComponent<SphericalTransformComponent>();
            auto pos = pTransform->GetSphericalPosition();
            auto renderingComponent = pEntity->GetComponent<SphericalRenderingComponent>();
            auto visibility = renderingComponent->GetSphericalVisibility();

            auto radius = SphericalEffect::GetRadius();
            auto dist = SphericalDistance(pos / radius, cameraPos / radius, 1.); // dist is Chi 
            auto mu = timer->GetMu();

            if (mu < dist)
                renderingComponent->SetSphericalVisibility(SphericalVisibility::VISIBLE_NONE);
            else
            {
                if (mu >= dist && mu <= (XM_2PI - dist))
                {
                    renderingComponent->SetSphericalVisibility(SphericalVisibility::VISIBLE_FRONT);
                }
                else //mu > (2 * XM_PI - dist)
                {
                    renderingComponent->SetSphericalVisibility(SphericalVisibility::VISIBLE_ALL);
                }
            }
        });

    *radiusUpdateSystem = new RadiusUpdateSystem(timer, renderSystem, cameraTransform);

    *animationSystem = new ActionSystem<InputComponent>(
        [timer, initialSimulationMu] (Entity* pEntity, double deltaTime) {
            static auto isAnimation = true;

            double radius = SphericalEffect::GetRadius();
            if (isAnimation)
            {
                if (radius > 0.05)
                {
                    timer->AddDelta(deltaTime);
                }
                else
                    isAnimation = false;
            }
        });

    *soundSystem = new SoundSystem(pSound, *selectionSystem, cameraTransform);

    return timer;
}

FriedmannTimer::FriedmannTimer(double initialSimulationTime, double frameTimeLimit, double muCoeff)
{
    m_currentSimulationTime = initialSimulationTime;
    m_frameTimeLimit = frameTimeLimit;
    m_muCoeff = muCoeff;
}

void FriedmannTimer::AddDelta(double deltaTime)
{
    m_currentSimulationTime += deltaTime;
    m_currentFrameTime += deltaTime;
}

bool FriedmannTimer::IsTimeToRepaint()
{
    if (m_currentFrameTime >= m_frameTimeLimit || m_currentFrameTime <= -m_frameTimeLimit)
    {
        m_currentFrameTime = 0;
        return true;  
    }
    return false;
}

double FriedmannTimer::GetSimulationTime()
{
    return m_currentSimulationTime;
}

double FriedmannTimer::GetMu()
{
    return m_currentSimulationTime * m_muCoeff;
}

double FriedmannTimer::GetFrameTime()
{
    return m_currentFrameTime;
}

void FriedmannTimer::SetFrameTime(double newTime)
{
    m_currentFrameTime = newTime;
}

RadiusUpdateSystem::RadiusUpdateSystem(FriedmannTimer * timer, SphericalRenderSystem* renderSystem, SphericalTransformComponent* cameraTransform)
{
    SubscribeToComponentType<SphericalTransformComponent>();
    SubscribeToComponentType<DopplerComponent>();

    m_timer = timer;
    m_renderSystem = renderSystem;
    m_cameraTransform = cameraTransform;
    m_radiusFunctiom  = [](double mu) { return 2 * (1 - cos(mu)); };
}

void RadiusUpdateSystem::Execute(double deltaTime)
{
    double mu = m_timer->GetMu();
    //double radius = 2 * (1 - cos(mu));
    double radius = m_radiusFunctiom(mu);

    m_renderSystem->SetRadius(radius);
    SphericalDopplerEffect::SetMu(mu);

    if (m_timer->IsTimeToRepaint())
    {
        UpdateFriedmannWindow(mu);
    }

}

SoundSystem::SoundSystem(Sound* pSound, SelectionSystem* pSelectionSystem, SphericalTransformComponent* pCameraTransform)
{
    m_pSound = pSound;
    m_pSelectionSystem = pSelectionSystem;
    m_pCameraTransform = pCameraTransform;
}

void SoundSystem::Execute(double deltaTime)
{
    auto pSelectedEntity = m_pSelectionSystem->GetSelectedEntity();
    if (pSelectedEntity != nullptr)
    {
        float pitch;
        const auto& view = m_pCameraTransform->GetView();

        auto pSphTransform = pSelectedEntity->GetComponent<SphericalTransformComponent>();
        auto sphPosWorld = pSphTransform->GetSphericalPosition();
        auto sphPosView = Vector4::Transform(sphPosWorld, view); //pos_view

        auto radius = SphericalEffect::GetRadius();
        double chi = acos(sphPosView.w / radius);

        if (sphPosView.z < 0)
            chi = XM_2PI - chi;

        pitch = chi / XM_2PI; 
        //���� ��� ������: � ���� ������ ���� ����������� �������, �� ��� �������� �����, ��� ����, � ���������� �� ������� � ��!
        //pitch of sound - depends on frequency!
        //pitch ranges from -1 to +1, playback defaults to 0 (which is no pitch-shifting)
        //�� ��������� ������ ����� � ��������
        m_pSound->SetVolume(1.);
        m_pSound->SetPitch(pitch);
    }
    else
    {
        m_pSound->SetVolume(0.);
        m_pSound->SetPitch(-0.5f);
    }
}


// �� ������ ������: ��� ��� ��������� (���� ������� �� ��) - �� ��������� �� ������ 21.02.2022