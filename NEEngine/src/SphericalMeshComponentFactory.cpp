#include "pch.h"
#include "SphericalMeshComponentFactory.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

MeshComponent* SphericalMeshComponentFactory::CreateSphericalSphere(double radius, int sliceCount, int stackCount)
{
	int triCount = 0;

	auto phiStep = XM_PI / stackCount;
	auto thetaStep = XM_2PI / sliceCount;

	std::vector<VertexData> vertices;
	std::vector<WORD> indices;
}

MeshComponent* SphericalMeshComponentFactory::CreateSphericalMeshFromFile()
{
	return nullptr;
}
