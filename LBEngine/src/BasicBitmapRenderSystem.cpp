#include "pch.h"
#include "BasicBitmapRenderSystem.h"

#include "BitmapComponent.h"
#include "Entity.h"
#include "TransformComponent.h"
#include "Texture.h"
#include "EuclideanMeshComponentFactory.h"

// Shaders
#include "VertexShader.h"
#include "PixelShader.h"

#include "Game.h"

// TODO: implement universal BitmapRenderSystem
// and default effect - BasicBitmapEffect

BasicBitmapRenderSystem::BasicBitmapRenderSystem() : System(), game(Game::GetInstance())
{
	SubscribeToComponentType<TransformComponent>();
	SubscribeToComponentType<BitmapComponent>();

	Initialize();

	m_isDrawing = true;
}

void BasicBitmapRenderSystem::Initialize()
{
	// shaders
	g_d3dVertexShader = game.CreateVertexShaderFromBytecode(g_vs, sizeof(g_vs));
	g_d3dPixelShader = game.CreatePixelShaderFromBytecode(g_ps, sizeof(g_ps));

	//input assembly:
	D3D11_INPUT_ELEMENT_DESC vertexLayoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, offsetof(EuclideanMeshComponentFactory::VertexData, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	//Once an input-layout object is created from a shader signature, the input-layout object can be reused with any other shader that has an identical input signature (semantics included). 
	g_d3dInputLayout = game.CreateInputLayout(vertexLayoutDesc, _countof(vertexLayoutDesc), g_vs, sizeof(g_vs));

	//buffers:
	D3D11_BUFFER_DESC constantBufferDesc;
	ZeroMemory(&constantBufferDesc, sizeof(D3D11_BUFFER_DESC));
	constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	constantBufferDesc.CPUAccessFlags = 0;
	constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	constantBufferDesc.ByteWidth = sizeof(PerObjectVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Object] = game.CreateBuffer(constantBufferDesc);

	constantBufferDesc.ByteWidth = sizeof(PerFrameVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Frame] = game.CreateBuffer(constantBufferDesc);

	constantBufferDesc.ByteWidth = sizeof(PerApplicationVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Application] = game.CreateBuffer(constantBufferDesc);

	//sampler (for texture)
	D3D11_SAMPLER_DESC samplerDesc;
	ZeroMemory(&samplerDesc, sizeof(D3D11_SAMPLER_DESC));
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	g_d3dSamplerState = game.CreateSamplerState(samplerDesc);
}

void BasicBitmapRenderSystem::Execute(double)
{	
	std::stable_sort(m_opaqueEntities.begin(), m_opaqueEntities.end(), [](Entity* e1, Entity* e2) -> bool {
		return e1->GetComponent<TransformComponent>()->GetPosition().z < e2->GetComponent<TransformComponent>()->GetPosition().z;
	});	//��������� �� ��������: ������� ������� z...

	std::stable_sort(m_nonOpaqueEntities.begin(), m_nonOpaqueEntities.end(), [](Entity* e1, Entity* e2) -> bool {
		return e1->GetComponent<TransformComponent>()->GetPosition().z > e2->GetComponent<TransformComponent>()->GetPosition().z;
	});	//��������� �� �����������: ������� ������� z...

	//TODO: fix 
	//������� ��� ������� �������, ����� ������� �� � ������

	auto& game = Game::GetInstance();
	auto pDeviceContext = game.GetDeviceContext();
	auto pDevice = game.GetDevice();

	auto pConstantBuffer = game.g_d3dVSConstantBuffers[2];

	//Input Assembler Stage - common
	pDeviceContext->IASetInputLayout(game.g_d3dInputLayout);

	//Vertex Shader Stage
	pDeviceContext->VSSetShader(game.g_d3dVertexShader, nullptr, 0);
	pDeviceContext->VSSetConstantBuffers(0, 3, game.g_d3dVSConstantBuffers);

	//Rasterizer Stage
	pDeviceContext->RSSetState(game.g_d3dRasterizerState);
	pDeviceContext->RSSetViewports(1, &game.g_Viewport);

	//Pixel Shader Stage
	pDeviceContext->PSSetShader(game.g_d3dPixelShader, nullptr, 0);
	//g_d3dDeviceContext->PSSetConstantBuffers(0, 1, &g_d3dPSConstantBuffer);
	pDeviceContext->PSSetSamplers(0, 1, &game.g_d3dSamplerState);

	//Output Merger Stage (merges the output from the pixel shader onto the color and depth buffers)
	pDeviceContext->OMSetRenderTargets(1, &game.g_d3dRenderTargetView, game.g_d3dDepthStencilView);
	pDeviceContext->OMSetDepthStencilState(game.g_d3dDepthStencilState, 1); //1 is Reference value to perform against when doing a depth-stencil test.
	pDeviceContext->OMSetBlendState(game.g_d3dBlendState, 0, 0xffffffff);


	//������� opaque (front-to-back)
	for (auto pEntity : m_opaqueEntities)
	{
		Render(pEntity, pDeviceContext, pConstantBuffer);
	}


	//����� non opaque (back-to-front)
	for (auto pEntity : m_nonOpaqueEntities)
	{
		Render(pEntity, pDeviceContext, pConstantBuffer);
	}
}

void BasicBitmapRenderSystem::AddEntity(Entity* pEntity)
{
	BitmapComponent* bitmapComponent = pEntity->GetComponent<BitmapComponent>();

	if (bitmapComponent->IsOpaque())
		m_opaqueEntities.push_back(pEntity);
	else
		m_nonOpaqueEntities.push_back(pEntity);

	m_entities.push_back(pEntity);

}

void BasicBitmapRenderSystem::Render(Entity* pEntity, ID3D11DeviceContext* pDeviceContext, ID3D11Resource* pConstantBuffer)
{
	BitmapComponent* p_bitmapComponent = pEntity->GetComponent<BitmapComponent>();
	TransformComponent* p_transformComponent = pEntity->GetComponent<TransformComponent>();
	{

		unsigned int stride;
		unsigned int offset;

		// Set vertex buffer stride and offset.
		stride = sizeof(BitmapComponent::VertexType);
		offset = 0;

		// Set the vertex buffer to active in the input assembler so it can be rendered.
		pDeviceContext->IASetVertexBuffers(0, 1, &p_bitmapComponent->m_vertexBuffer, &stride, &offset);

		// Set the index buffer to active in the input assembler so it can be rendered.
		pDeviceContext->IASetIndexBuffer(p_bitmapComponent->m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

		// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
		pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		Texture* pTexture;
		if (( pTexture = p_bitmapComponent->m_spriteSheet) != nullptr)
		{     
			//Pixel Shader Stafe - unique 4 every stage
			auto shaderResource = pTexture->GetTexture();
			pDeviceContext->PSSetShaderResources(0, 1, &shaderResource);
		}

		if(p_transformComponent != nullptr)
			pDeviceContext->UpdateSubresource(pConstantBuffer, 0, nullptr, &p_transformComponent->GetWorld(), 0, 0);

		//DRAW
		pDeviceContext->DrawIndexed(p_bitmapComponent->m_indexCount, 0, 0);
	}
}
