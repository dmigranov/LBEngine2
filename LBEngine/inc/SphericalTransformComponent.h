#pragma once
#include "TransformComponent.h"
class SphericalTransformComponent :
    public TransformComponent
{ 
public:
    SphericalTransformComponent();
    SphericalTransformComponent(double x, double y, double z);
    SphericalTransformComponent(double x, double y, double z, double rx, double ry, double rz);
    SphericalTransformComponent(DirectX::SimpleMath::Vector3 position);
    SphericalTransformComponent(DirectX::SimpleMath::Vector3 position, DirectX::SimpleMath::Vector3 rotation);

    virtual void Move(DirectX::SimpleMath::Vector3 v) override;
    virtual void Move(double dx, double dy, double dz) override;
    virtual void MoveAbsolute(double x, double y, double z, double w);
    virtual void Rotate(DirectX::SimpleMath::Vector3 r) override;
    virtual void Rotate(double deltaPitch, double deltaYaw, double deltaRoll) override;
    virtual void SetPitchYawRoll(double pitch, double yaw, double roll) override;
    virtual DirectX::SimpleMath::Vector4 GetSphericalPosition();
    //void SetWorld(const DirectX::SimpleMath::Matrix& world); //temporary method, for debug only

    void SetScaleMatrix(const DirectX::SimpleMath::Matrix& scale);

    static void SetRadius(double radius);
protected:
    virtual void Recalculate() override;
    virtual void RecalculateView() override;

private:
    double m_yaw = 0., m_pitch = 0., m_roll = 0.;
    static double m_radius;

    DirectX::SimpleMath::Matrix T = DirectX::SimpleMath::Matrix::Identity; // represents the translation of the camera in world space
    DirectX::SimpleMath::Matrix R = DirectX::SimpleMath::Matrix::Identity,
        RYaw = DirectX::SimpleMath::Matrix::Identity,
        RPitch = DirectX::SimpleMath::Matrix::Identity,
        RRoll = DirectX::SimpleMath::Matrix::Identity; // represents camera orientation
    DirectX::SimpleMath::Matrix S = DirectX::SimpleMath::Matrix::Identity;

    DirectX::SimpleMath::Vector4 m_position;
};