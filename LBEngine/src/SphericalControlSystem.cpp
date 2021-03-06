#include "pch.h"
#include "SphericalControlSystem.h"

#include "Entity.h"
#include "InputComponent.h"
#include "SphericalTransformComponent.h"
#include "SphericalCameraComponent.h"

#include "SphericalMath.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

SphericalControlSystem::SphericalControlSystem(double movementSpeed, double rotationSpeed) : ActionSystem([movementSpeed, rotationSpeed, this](Entity* pEntity, double deltaTime) {
    auto pTransform = pEntity->GetComponent<SphericalTransformComponent>();
    auto pInput = pEntity->GetComponent<InputComponent>();
    auto kbs = pInput->GetKeyboardState();
    auto ms = pInput->GetMouseState();

    double m_dx = 0, m_dy = 0;


    if(pInput->IsRelative())
    {
        //pitch - around x, yaw - around y
        m_dx = -ms.x * rotationSpeed * deltaTime;
        m_dy = ms.y * rotationSpeed * deltaTime;

        /*
        if(kbs.Q)
            m_dx = rotationSpeed * deltaTime;
        if (kbs.E)
            m_dx = -rotationSpeed * deltaTime;
        if (kbs.O)
            m_dy = rotationSpeed * deltaTime;
        if (kbs.L)
            m_dy = -rotationSpeed * deltaTime;
            */

        m_pitch += m_dy;
        m_yaw += m_dx;

        m_pitch = std::max<double>(-m_pitchLimit, m_pitch);
        m_pitch = std::min<double>(+m_pitchLimit, m_pitch);

        // keep longitude in sane range by wrapping
        if (m_yaw > DirectX::XM_PI)
            m_yaw -= DirectX::XM_2PI;
        else if (m_yaw < -DirectX::XM_PI)
            m_yaw += DirectX::XM_2PI;

        // OLD CODE BEGIN
        RYaw = SphericalRotationXZ(-m_yaw);
        RPitch = SphericalRotationYZ(-m_pitch);
        R = RPitch * RYaw;
        // OLD CODE END

        //pTransform->SetPitchYawRoll(m_pitch, m_yaw, 0); //set lower
    }

    double dx = 0, dy = 0, dz = 0;
    if (kbs.W)
        dz = movementSpeed * deltaTime;
    if (kbs.S)
        dz = -movementSpeed * deltaTime;
    if (kbs.A)
        dx = -movementSpeed * deltaTime;
    if (kbs.D)
        dx = movementSpeed * deltaTime;
    if (kbs.Q)
        dy = -movementSpeed * deltaTime;
    if (kbs.Z)
        dy = movementSpeed * deltaTime;

    if (kbs.Back)
        pTransform->SetPitchYawRoll(XM_2PI - m_pitch, m_yaw + XM_PI, 0); //todo: ?????????!
    else
        pTransform->SetPitchYawRoll(m_pitch, m_yaw, 0);

    if (dx != 0 || dz != 0 || dy != 0)
    {
        Vector4 tempVector(dx, dy, dz, 0);
        tempVector = Vector4::Transform(tempVector, RYaw);

        pTransform->Move(tempVector.x, tempVector.y, tempVector.z);
        //pTransform->Move(dx, dy, dz);
    }

    pInput->SetRelative(ms.leftButton ? true : false);

})
{ }

/*  
    Matrix dT =  SphericalRotationZW(dz) * SphericalRotationXW(dx);

    //T = T * RYaw * dT * RYaw.Transpose();	//the T^1 matrix that can be used to calculate view = T^-1 * R^-1
    T = RYaw.Transpose() * dT * RYaw * T;
    auto transformMatrix = R * T;

    pTransform->SetWorld(transformMatrix);
*/