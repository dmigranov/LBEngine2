#include "pch.h"
#include "SphericalTransformComponent.h"

//todo: �����������

void SphericalTransformComponent::Move(DirectX::SimpleMath::Vector3 v)
{
	TransformComponent::Move(v); //todo: ��������, ��� ���� ����� ��� ��������
}

void SphericalTransformComponent::Move(double x, double y, double z)
{
	TransformComponent::Move(x, y, z); //todo: ��������, ��� ���� ����� ��� ��������
}

void SphericalTransformComponent::Rotate(DirectX::SimpleMath::Vector3 r)
{
	//todo
}

void SphericalTransformComponent::Rotate(double rx, double ry, double rz)
{
	//todo
}

void SphericalTransformComponent::Recalculate()
{
	TransformComponent::Recalculate(); //todo: ��������, ��� ���� ����� ��� ��������



}

void SphericalTransformComponent::RecalculateView()
{

}

void SphericalTransformComponent::SetWorld(const DirectX::SimpleMath::Matrix& world)
{
	auto realWorld = world;
	if (m_pParent != nullptr)
		realWorld = realWorld * m_pParent->GetWorld();
	m_world = realWorld;

	//m_view = 

	m_shouldRecalcWorld = false;
	//m_shouldRecalcView = false;
}

