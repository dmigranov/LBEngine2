#pragma once
#include "TransformComponent.h"
class HyperbolicTransformComponent :
    public TransformComponent
{
public:
    HyperbolicTransformComponent();
    HyperbolicTransformComponent(double x, double y, double z);
    HyperbolicTransformComponent(double x, double y, double z, double rx, double ry, double rz);
    HyperbolicTransformComponent(DirectX::SimpleMath::Vector3 position);
    HyperbolicTransformComponent(DirectX::SimpleMath::Vector3 position, DirectX::SimpleMath::Vector3 rotation);

    virtual void Move(DirectX::SimpleMath::Vector3 v) override;
    virtual void Move(double dx, double dy, double dz) override;
    virtual void Rotate(DirectX::SimpleMath::Vector3 r) override;
    virtual void Rotate(double deltaPitch, double deltaYaw, double deltaRoll) override;
    virtual void SetPitchYawRoll(double pitch, double yaw, double roll) override;
    DirectX::SimpleMath::Vector4 GetHyperbolicPosition();
protected:
    virtual void Recalculate() override;
    virtual void RecalculateView() override;

private:
    double m_yaw = 0., m_pitch = 0., m_roll = 0.;

    DirectX::SimpleMath::Matrix T = DirectX::SimpleMath::Matrix::Identity; // represents the translation of the camera in world space
    DirectX::SimpleMath::Matrix R = DirectX::SimpleMath::Matrix::Identity,
        RYaw = DirectX::SimpleMath::Matrix::Identity,
        RPitch = DirectX::SimpleMath::Matrix::Identity,
        RRoll = DirectX::SimpleMath::Matrix::Identity; // represents camera orientation

    DirectX::SimpleMath::Vector4 m_position;
};

