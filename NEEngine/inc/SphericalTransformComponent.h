#pragma once
#include "TransformComponent.h"
class SphericalTransformComponent :
    public TransformComponent
{ 
    //todo
public:
    SphericalTransformComponent();
    //todo: constructors

    virtual void Move(DirectX::SimpleMath::Vector3 v) override;
    virtual void Move(double x, double y, double z) override;
    virtual void Rotate(DirectX::SimpleMath::Vector3 r) override;
    virtual void Rotate(double deltaPitch, double deltaYaw, double deltaRoll) override;

    virtual void Recalculate() override;
    virtual void RecalculateView() override;

    void SetWorld(const DirectX::SimpleMath::Matrix& world); //��������� �����

private:
    DirectX::SimpleMath::Matrix T = DirectX::SimpleMath::Matrix::Identity; // represents the translation of the camera in world space
    DirectX::SimpleMath::Matrix R = DirectX::SimpleMath::Matrix::Identity,
        RYaw = DirectX::SimpleMath::Matrix::Identity,
        RPitch = DirectX::SimpleMath::Matrix::Identity,
        RRoll = DirectX::SimpleMath::Matrix::Identity; // represents camera orientation
};

