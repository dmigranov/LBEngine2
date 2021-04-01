#pragma once
#include "Effect.h"

class SphericalExpFogEffect :
    public Effect
{
public:
    // ������������ ����� Effect
    virtual bool Initialize() override;
    virtual bool Deinitialize() override;
    virtual bool SetMaterial(const Entity* pEntity) override;
    ~SphericalExpFogEffect();

private:
    std::string		m_vsFileName;
    std::string		m_psFileName;

    ID3D11VertexShader* g_d3dVertexShader = nullptr;
    ID3D11PixelShader* g_d3dPixelShader = nullptr;

    ID3D11Buffer* g_d3dVSConstantBuffer; //�� � ������� ������� ���� ������ �� ������ ����
    //VS ����� - ������ CB_Object
    ID3D11Buffer* g_d3dPSConstantBuffer;

};

