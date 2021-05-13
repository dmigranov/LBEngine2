#include "pch.h"
#include "ToricExpFogEffect.h"

#include "Texture.h"
#include "Scene.h"

#include "EuclideanMeshComponentFactory.h"	//��� ������� ���������

#include "SphericalTransformComponent.h"
#include "SphericalCameraComponent.h"
#include "Entity.h"

#include "Game.h"

#include "TorExpVertexShader.h"
#include "PixelShader.h" 

using namespace DirectX;
using namespace DirectX::SimpleMath;

ToricExpFogEffect::ToricExpFogEffect(Texture* pTexture, double fogDensity, DirectX::XMVECTORF32 fogColor) : game(Game::GetInstance())
{
	m_magic = "ToricExpFog";
	m_pTexture = pTexture;
	perApplicationVSConstantBuffer.density = fogDensity;
	perApplicationPSConstantBuffer.fogColor = fogColor;
	Initialize();
}

bool ToricExpFogEffect::Initialize()
{
	//shaders
	g_d3dVertexShader = game.CreateVertexShaderFromBytecode(g_torexpvs, sizeof(g_torexpvs));
	g_d3dPixelShader = game.CreatePixelShaderFromBytecode(g_ps, sizeof(g_ps));

	//input assembly:
	D3D11_INPUT_ELEMENT_DESC vertexLayoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, offsetof(EuclideanMeshComponentFactory::VertexData, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	g_d3dInputLayout = game.CreateInputLayout(vertexLayoutDesc, _countof(vertexLayoutDesc), g_torexpvs, sizeof(g_torexpvs));

	//������:
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


	constantBufferDesc.ByteWidth = sizeof(PerApplicationPSConstantBuffer);
	g_d3dPSConstantBuffer = game.CreateBuffer(constantBufferDesc);

	//todo: instance buffer

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

	return false;
}

void ToricExpFogEffect::Deinitialize()
{
	SafeRelease(g_d3dVSConstantBuffers[CB_Application]);
	SafeRelease(g_d3dVSConstantBuffers[CB_Frame]);
	SafeRelease(g_d3dVSConstantBuffers[CB_Object]);
	SafeRelease(g_d3dPSConstantBuffer);

	SafeRelease(g_d3dSamplerState);

	SafeRelease(g_d3dInputLayout);

	SafeRelease(g_d3dVertexShader);
	SafeRelease(g_d3dPixelShader);
}

void ToricExpFogEffect::UpdatePerObject(const Entity* pEntity)
{
	auto pCameraComponent = game.GetScene()->GetCamera()->GetComponent<CameraComponent>();
	perApplicationVSConstantBuffer.proj = pCameraComponent->GetProj();
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Application], &perApplicationVSConstantBuffer);

	const auto& view = (game.GetScene())->GetCamera()->GetComponent<TransformComponent>()->GetView();
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Frame], &view);

	auto pTransformComponent = pEntity->GetComponent<TransformComponent>();
	const auto& world = pTransformComponent->GetWorld();
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Object], &world);

	//vertex shader stage
	game.VSSetShader(g_d3dVertexShader);
	game.VSSetConstantBuffers(3, g_d3dVSConstantBuffers);

	//pixel shader stage
	game.PSSetSampler(g_d3dSamplerState);
	game.PSSetShader(g_d3dPixelShader);
	if (m_pTexture != nullptr)
	{
		auto shaderResource = m_pTexture->GetTexture();
		game.PSSetShaderResources(1, &shaderResource);
	}
}

void ToricExpFogEffect::UpdatePerScene()
{
	//todo: for optimisation
}

void ToricExpFogEffect::UpdatePerApplication()
{
	//todo: for optimisation
}

unsigned int ToricExpFogEffect::GetVertexBufferSize() const
{
	return sizeof(EuclideanMeshComponentFactory::VertexData);
}

const std::type_info& ToricExpFogEffect::GetVertexDataType()
{
	return typeid(EuclideanMeshComponentFactory::VertexData);
}

ToricExpFogEffect::~ToricExpFogEffect()
{
	Deinitialize();
}
