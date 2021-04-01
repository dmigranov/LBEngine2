#pragma once
#include "Effect.h"

class Game;

class SphericalExpFogEffect :
    public Effect
{
public:
    struct VertexPosTex
    {
        DirectX::XMFLOAT4 Position;  //���������� ����� � ������������� ������������
        DirectX::XMFLOAT2 TexCoord;
    };

    // ������������ ����� Effect
    virtual bool Initialize() override;
    virtual bool Deinitialize() override;
    virtual bool SetMaterial(const Entity* pEntity) override;
    ~SphericalExpFogEffect();
protected:
    std::string magic = "SphericalExpFog";

private:
    //std::string		m_vsFileName;
    //std::string		m_psFileName;

    ID3D11InputLayout* g_d3dInputLayout = nullptr;

    ID3D11VertexShader* g_d3dVertexShader = nullptr;
    ID3D11PixelShader* g_d3dPixelShader = nullptr;

    ID3D11Buffer* g_d3dVSConstantBuffer; //�� � ������� ������� ���� ������ �� ������ ����
    //VS ����� - ������ CB_Object
    ID3D11Buffer* g_d3dPSConstantBuffer;

    Game& game;// = Game::GetInstance();

};

