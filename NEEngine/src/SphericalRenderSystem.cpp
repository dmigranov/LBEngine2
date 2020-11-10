#include "pch.h"
#include "SphericalRenderSystem.h"

#include "Entity.h"
#include "MeshComponent.h"

class SphericalTransformComponent;


SphericalRenderSystem::SphericalRenderSystem()
{
	//todo:
	//��� ������� ������������� ������� Rendering'�?
	//������ ��� ��� ���������, ����� SphericalTransformComponent, ���� � ���� ��������� ����� ��
	//����� ���: SphericalMeshComponent � TransformComponent? 

	//todo: �������� ��� ������: ��� - ��� ���?
	//MeshComponent?
	//SphericalMeshComponent?
	//��� ����� SphericalTransformComponent?
	//����������� �� TransformComponent, ����� �� ���������, �� ���������� ������ �������!

	//SubscribeToComponentType<TransformComponent>();
	SubscribeToComponentType<MeshComponent>();

	m_isDrawing = true;
}

void SphericalRenderSystem::Execute(double deltaTime)
{
	auto& game = Game::GetInstance();
	ID3D11DeviceContext* pDeviceContext = game.g_d3dDeviceContext;
	auto pDevice = game.g_d3dDevice;

	auto pConstantBuffer = game.g_d3dVSConstantBuffers[2];

	//todo: ��� ������ ��������� ���������


	for (auto pEntity : m_entities)
	{
		Render(pEntity, pDeviceContext, pConstantBuffer);
	}
}

void SphericalRenderSystem::Render(Entity* pEntity, ID3D11DeviceContext* pDeviceContext, ID3D11Resource* pConstantBuffer)
{
	//SphericalTransformComponent* p_transformComponent = pEntity->GetComponent<SphericalTransformComponent>();
	MeshComponent* p_meshComponent = pEntity->GetComponent<MeshComponent>();


	// Input Assembler Stage - unique for every mesh
	// Set vertex buffer stride and offset.
	unsigned int stride = sizeof(MeshComponent::VertexPosTex); //todo?
	unsigned int offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	pDeviceContext->IASetVertexBuffers(0, 1, &p_meshComponent->g_d3dVertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	pDeviceContext->IASetIndexBuffer(p_meshComponent->g_d3dIndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	if (p_meshComponent->m_pTexture != nullptr)
	{     //Pixel Shader Stafe - unique 4 every stage
		auto shaderResource = p_meshComponent->m_pTexture->GetTexture();
		pDeviceContext->PSSetShaderResources(0, 1, &shaderResource);
	}


	//todo: ���������� ����������� ������ � ����������� �� ����������

}
