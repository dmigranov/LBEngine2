#pragma once

class MeshComponent;

class MeshComponentFactory
{
public:
	template<class VertexData> MeshComponent* CreateMeshComponent(int nv, VertexData* vertices, int ni, WORD* indices) {
		//todo: �������� � ����������� MeshComponent

		//todo: ������� ����� CreateSphericalMeshComponent
		//��� ������: �������� �� ������ ������ � ��������,
		//�� ����� � �������� ��������������� ��������

		return nullptr;
	}
};

