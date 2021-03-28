#pragma once
#include "Effect.h"
class SphericalExpFogEffect :
    public Effect
{
public:
    // ������������ ����� Effect
    virtual void Initialize() override;
    virtual void Deinitialize() override;
    virtual void SetMaterial(const Entity* pEntity) override;

private:
    std::string		m_vsFileName;
    std::string		m_psFileName;

    ID3D11VertexShader* g_d3dVertexShader = nullptr;
    ID3D11PixelShader* g_d3dPixelShader = nullptr;

    ID3D11Buffer* g_d3dVSConstantBuffer; //�� � ������� ������� ���� ������ �� ������ ����
    //VS ����� - ������ CB_Object
    ID3D11Buffer* g_d3dPSConstantBuffer;

};

