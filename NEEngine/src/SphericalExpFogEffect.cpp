#include "pch.h"
#include "SphericalExpFogEffect.h"

#include "Game.h"

bool SphericalExpFogEffect::Initialize()
{
	//assert(g_d3dDevice);
	
	//��� ���������� ������ �� ������� � �������� �����, ��������� �������
	//input assembly ���� ���?

	return true;
}

bool SphericalExpFogEffect::Deinitialize()
{
	// �������, ������� � �������� ���� ��������� ��������
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
}
