#include "pch.h"
#include "SphericalExpFogEffect.h"

void SphericalExpFogEffect::Initialize()
{
	//��� ���������� ������ �� ������� � �������� �����, ��������� �������
	//input assembly ���� ���?
}

void SphericalExpFogEffect::Deinitialize()
{
	// �������, ������� � �������� ���� ��������� ��������
}

void SphericalExpFogEffect::SetMaterial(const Entity* pEntity)
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
