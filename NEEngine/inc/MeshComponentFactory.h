#pragma once

class MeshComponent;

class MeshComponentFactory
{
public:
	template<class VertexData> MeshComponent* CreateMeshComponent(int nv, VertexData* vertices, int ni, WORD* indices) {
		MeshComponent* returnMesh = nullptr;

		//todo: ������� ����� CreateSphericalMeshComponent
		//��� ������: �������� �� ������ ������ � ��������,
		//�� ����� � �������� ��������������� ��������

		return returnMesh;
	}
};

