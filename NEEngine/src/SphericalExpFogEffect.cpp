#include "pch.h"
#include "SphericalExpFogEffect.h"
#include "Texture.h"
#include "Scene.h"

#include "SphericalMeshComponentFactory.h"	//��� ������� ���������

#include "SphericalTransformComponent.h"
#include "SphericalCameraComponent.h"
#include "Entity.h"

#include "VertexShader.h" // generated from BasicVertexShader.hlsl
#include "PixelShader.h" // generated from BasicPixelShader.hlsl

#include "SphExpVertexShader.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;

#include "Game.h"

bool SphericalExpFogEffect::isSpherical = true;

SphericalExpFogEffect::SphericalExpFogEffect(Texture* pTexture, double fogDensity, DirectX::XMVECTORF32 fogColor) : game(Game::GetInstance())
{
	m_magic = "SphericalExpFog";
	m_pTexture = pTexture;
	perApplicationVSConstantBuffer.density = fogDensity;
	perApplicationPSConstantBuffer.fogColor = fogColor;
	Initialize();
}

bool SphericalExpFogEffect::Initialize()
{
	//shaders
	g_d3dVertexShaderSph = game.CreateVertexShaderFromBytecode(g_sphexpvs, sizeof(g_sphexpvs));
	g_d3dPixelShader = game.CreatePixelShaderFromBytecode(g_ps, sizeof(g_ps));

	//input assembly:
	D3D11_INPUT_ELEMENT_DESC vertexLayoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, offsetof(SphericalMeshComponentFactory::VertexData, Position), D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	g_d3dInputLayout = game.CreateInputLayout(vertexLayoutDesc, _countof(vertexLayoutDesc), g_vs, sizeof(g_vs));


	//������:
	D3D11_BUFFER_DESC constantBufferDesc;
	ZeroMemory(&constantBufferDesc, sizeof(D3D11_BUFFER_DESC));

	constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	constantBufferDesc.CPUAccessFlags = 0;
	constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	//we will update the contents of buffers using the ID3D11DeviceContext::UpdateSubresource method and this method expects constant buffers to be initialized with D3D11_USAGE_DEFAULT usage flag and buffers that are created with the D3D11_USAGE_DEFAULT flag must have their CPUAccessFlags set to 0.
	//todo: �����, ����� ������� Dynamic, ���� ��������� ����� �����������?!! ��������

	constantBufferDesc.ByteWidth = sizeof(PerObjectVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Object] = game.CreateBuffer(constantBufferDesc);

	constantBufferDesc.ByteWidth = sizeof(PerFrameVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Frame] = game.CreateBuffer(constantBufferDesc);

	constantBufferDesc.ByteWidth = sizeof(PerApplicationVSConstantBuffer);
	g_d3dVSConstantBuffers[CB_Application] = game.CreateBuffer(constantBufferDesc);



	constantBufferDesc.ByteWidth = sizeof(PerApplicationPSConstantBuffer);
	g_d3dPSConstantBuffer = game.CreateBuffer(constantBufferDesc);


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

	return true;
}


void SphericalExpFogEffect::UpdatePerObject(const Entity* pEntity)
{
	// ������ ����������� ����������� ������, 
	// ��� �� ������������ ������ ������� � input assembly

	//todo: !!!!!��������������!!!!!

	// �������� ���� Clear(mistColor, 1.0f, 0) ������������ ����� ����������� ���, �� ��� �������������:
	// � ���� �������� ���������? ������ ����� ����� ������������ ��� ������

	// We will update the contents of buffers using the ID3D11DeviceContext::UpdateSubresource method and this method expects constant buffers to be initialized with D3D11_USAGE_DEFAULT usage flag and buffers that are created with the D3D11_USAGE_DEFAULT flag must have their CPUAccessFlags set to 0.
	// When UpdateSubresource returns, the application is free to change or even free the data pointed to by pSrcData because the method has already copied/snapped away the original contents. 

	auto pSphCameraComponent = game.GetScene()->GetCamera()->GetComponent<SphericalCameraComponent>();
	perApplicationVSConstantBuffer.projFront = pSphCameraComponent->GetFrontSphericalProj();
	perApplicationVSConstantBuffer.projBack = pSphCameraComponent->GetBackSphericalProj(); 
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Application], &perApplicationVSConstantBuffer);

	auto view = (game.GetScene())->GetView();
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Frame], &view);

	SphericalTransformComponent* pTransformComponent = pEntity->GetComponent<SphericalTransformComponent>();
	const auto& world = pTransformComponent->GetWorld();
	game.UpdateSubresource(g_d3dVSConstantBuffers[ConstantBuffer::CB_Object], &world);


	game.UpdateSubresource(g_d3dPSConstantBuffer, &perApplicationPSConstantBuffer);

	//input assembly stage
	game.IASetInputLayout(g_d3dInputLayout);

	//vertex shader stage
	game.VSSetShader(g_d3dVertexShaderSph);
	game.VSSetConstantBuffers(3, g_d3dVSConstantBuffers);

	//pixel shader stage
	game.PSSetSampler(g_d3dSamplerState);
	game.PSSetShader(g_d3dPixelShader);
	if (m_pTexture != nullptr)
	{     //Pixel Shader Stafe - unique 4 every stage
		auto shaderResource = m_pTexture->GetTexture();
		game.PSSetShaderResources(1, &shaderResource);
	}
}

void SphericalExpFogEffect::UpdatePerScene()
{
	//TODO: for optimisation...
}

void SphericalExpFogEffect::UpdatePerApplication()
{
	//TODO: for optimisation...
}

unsigned int SphericalExpFogEffect::GetVertexBufferSize() const
{
	return sizeof(SphericalMeshComponentFactory::VertexData);
}

const std::type_info& SphericalExpFogEffect::GetVertexDataType()
{
	return typeid(SphericalMeshComponentFactory::VertexData);
}

SphericalExpFogEffect::~SphericalExpFogEffect()
{
	Deinitialize();
}

void SphericalExpFogEffect::Deinitialize()
{
	// ������� � �������� ���� ��������� ��������

	SafeRelease(g_d3dVSConstantBuffers[CB_Application]);
	SafeRelease(g_d3dVSConstantBuffers[CB_Frame]);
	SafeRelease(g_d3dVSConstantBuffers[CB_Object]);
	SafeRelease(g_d3dPSConstantBuffer);

	SafeRelease(g_d3dSamplerState);

	SafeRelease(g_d3dInputLayout);

	SafeRelease(g_d3dVertexShaderSph);
	SafeRelease(g_d3dPixelShader);
}