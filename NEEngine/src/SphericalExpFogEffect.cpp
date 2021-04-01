#include "pch.h"
#include "SphericalExpFogEffect.h"

//����� �������, � ���� ����. �����������
//#include "VertexShader.h" // generated from BasicVertexShader.hlsl
//#include "PixelShader.h" // generated from BasicPixelShader.hlsl

#include "Game.h"

bool SphericalExpFogEffect::Initialize()
{
	//assert(g_d3dDevice);
	auto& game = Game::GetInstance();
	//��� ���������� ������ �� ������� � �������� �����, ��������� �������
	//input assembly ���� ���?

	g_d3dVertexShader = game.CreateVertexShaderFromBytecode(g_vs, sizeof(g_vs));
	g_d3dPixelShader = game.CreatePixelShaderFromBytecode(g_ps, sizeof(g_ps));

	return true;
}

bool SphericalExpFogEffect::Deinitialize()
{
	// �������, ������� � �������� ���� ��������� ��������
	SafeRelease(g_d3dVertexShader);
	SafeRelease(g_d3dPixelShader);

	return true;
}

bool SphericalExpFogEffect::SetMaterial(const Entity* pEntity)
{
	// ������ ����������� ����������� ������, 
	// ��� �� ������������ ������ ������� � input assembly
	// ����� ���� � ���������� SetMaterial,
	// �������� �������� ���-�� ��� (����� ���������)

	/*
	SetMaterialBegin();
	{
		SetVertexShaderBegin();
		SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
		SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));
		SetVertexShaderEnd();

		SetPixelShaderBegin();
		SetPixelShaderTexture2d("texture1", m_pTexture1);
		SetPixelShaderEnd();
	}
	SetMaterialEnd();
	*/

	return true;
}

SphericalExpFogEffect::~SphericalExpFogEffect()
{
	Deinitialize();
}
