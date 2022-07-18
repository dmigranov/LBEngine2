﻿#pragma once

#include "Geometries/ToricGeometry.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

int main(int argc, char* argv[])
{
    auto scene = InitializeToricGeometry(L"Test game", DirectX::Colors::PowderBlue,
        10, DirectX::SimpleMath::Vector3(30, 30, 30), 20, 0.9,
        true, false, false);

    auto resourceManager = Game::GetInstance().GetResourceManager();
    Texture* cubemapTexture = new Texture(L"cubemap.dds");


    Entity* cameraEntity = new Entity("camera1");
    auto cameraTransform = new ToricTransformComponent();
    auto cameraComponent = new CameraComponent();
    cameraComponent->SetFovY(DirectX::XM_PI / 3);
    cameraEntity->AddComponent<ToricTransformComponent>(cameraTransform);
    cameraEntity->AddComponent<CameraComponent>(cameraComponent);
    cameraEntity->AddComponent<InputComponent>(new InputComponent());
    scene->SetCamera(cameraEntity, cameraComponent);
    scene->AddEntity(cameraEntity);

    auto effect = new ToricExpFogEffect(cubemapTexture, 0.002, DirectX::Colors::PowderBlue);

    auto charInputComponent = new InputComponent();

    auto entity1 = new Entity();
    auto ttc1 = new ToricTransformComponent();
    {
        auto tmc1 = EuclideanMeshComponentFactory::CreateCube(3);
        tmc1->SetEffect(effect);
        entity1->AddComponent<ToricTransformComponent>(ttc1);
        entity1->AddComponent<MeshComponent>(tmc1);
        entity1->AddComponent<InputComponent>(charInputComponent);
        scene->AddEntity(entity1);

        entity1->AddComponent<UpdaterComponent>(new UpdaterComponent([](double deltaTime, Entity* pEntity) {
            auto pTransform = pEntity->GetComponent<ToricTransformComponent>();
            auto pInput = pEntity->GetComponent<InputComponent>();
            auto kbs = pInput->GetKeyboardState();
            auto ms = pInput->GetMouseState();

            Vector3 up(0, deltaTime * 200, 0);
            Vector3 right(deltaTime * 200, 0, 0);
            Vector3 fwd(0, 0, deltaTime * 200);

            if (kbs.R)
                pTransform->Move(up);
            if (kbs.F)
                pTransform->Move(-up);

            if (kbs.T)
                pTransform->Rotate(deltaTime, 0, 0);
            if (kbs.Y)
                pTransform->Rotate(-deltaTime, 0, 0);
            if (kbs.G)
                pTransform->Rotate(0, deltaTime, 0);
            if (kbs.H)
                pTransform->Rotate(0, -deltaTime, 0);
            if (kbs.B)
                pTransform->Rotate(0, 0, deltaTime);
            if (kbs.N)
                pTransform->Rotate(0, 0, -deltaTime);

            }));
    }

    return Game::GetInstance().StartGame();
}