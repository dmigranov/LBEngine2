#pragma once
#include "SphericalExpFogEffect.h"
class SphericalDopplerEffect :
    public SphericalExpFogEffect
{
public:
    struct PerApplicationPSConstantBufferDoppler 
    {
        DirectX::XMVECTORF32 fogColor = DirectX::Colors::CadetBlue;
        DirectX::XMVECTORF32 selectionColor = DirectX::Colors::GhostWhite;
        double velocity_coeff = 50000000.; //0
    };

    struct PerObjectPSConstantBuffer
    {
        int isSelected = 0;
        int pad1;
        int pad2;
        int pad3;
    };

    struct PerApplicationVSConstantBufferDoppler
    {
        DirectX::XMMATRIX projFront;
        DirectX::XMMATRIX projBack;
        double density = 0.1;
        //double radius = 1.;
        //double radiusOld = 1.;
        double mu = 0.;
    };

    SphericalDopplerEffect(Texture* pTexture, Texture* pTextureAlt, double fogDensity, DirectX::XMVECTORF32 fogColor);

    virtual bool Initialize() override;
    virtual void Deinitialize() override;

    virtual void UpdatePerObject(const Entity* pEntity, double deltaTime) override;

    virtual void Clean() override;

    void SetVelocityCoefficient(double velocity);
    double GetVelocityCoefficient();

    static double GetOldRadius();
    static void SetMu(double mu);

    //virtual void SetRadius(double radius) override;

    virtual void SetFogColor(DirectX::XMVECTORF32 fogColor) override;

private:
    PerApplicationPSConstantBufferDoppler   perApplicationPSConstantBuffer;
    PerObjectPSConstantBuffer               perObjectPSConstantBuffer;
    PerApplicationVSConstantBufferDoppler   perApplicationVSConstantBufferDoppler;


    ID3D11Buffer* g_d3dPerObjectPSConstantBuffer = nullptr;

    static double m_radiusOld;// = 1.;

    Texture* m_pTextureAlt = nullptr;

    static double m_eta;
};