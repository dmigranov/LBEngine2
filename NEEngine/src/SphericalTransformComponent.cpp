#include "pch.h"
#include "SphericalTransformComponent.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//todo: �����������

SphericalTransformComponent::SphericalTransformComponent()
{
}

void SphericalTransformComponent::Move(DirectX::SimpleMath::Vector3 v)
{
	//todo: multiply matrices...
	TransformComponent::Move(v); //todo: ��������, ��� ���� ����� ��� ��������
}

void SphericalTransformComponent::Move(double x, double y, double z)
{
	this->Move(Vector3(x, y, z));
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

	std::cerr << "SphericalTransformComponent::Recalculate()" << std::endl;
}

void SphericalTransformComponent::RecalculateView()
{
	//todo: ��������� �� ������ ����� - ����������
	//std::cerr << "SphericalTransformComponent::RecalculateView()" << std::endl;
}

void SphericalTransformComponent::SetWorld(const DirectX::SimpleMath::Matrix& world)
{
	//todo: ��������� - ���������?

	auto realWorld = world;
	if (m_pParent != nullptr)
		realWorld = realWorld * m_pParent->GetWorld();
	m_world = realWorld;

	m_view = m_world.Transpose();

	m_shouldRecalcWorld = false;
	m_shouldRecalcView = false;
}