#pragma once
#include "Component.h"

class AbstractMeshComponent : public Component
{
public:
	//todo: ������! ������ ���� ����� �������, ��� ��� ��� ������ ���� �� �������
	virtual void Render(DirectX::XMMATRIX world) = 0;
protected:
	ID3D11Buffer* g_d3dVertexBuffer = nullptr;
	ID3D11Buffer* g_d3dIndexBuffer = nullptr;
	ID3D11DeviceContext* deviceContext;

	ID3D11Resource* d3dConstantBuffer;     //todo: ����������� ������� ������ ���� � ������ ��� Effect!

	
};