#pragma once
#include "System.h"
class BasicBitmapRenderSystem :
    public System
{
public:
    struct PerApplicationVSConstantBuffer
    {
        DirectX::XMMATRIX proj;
    };

    struct PerFrameVSConstantBuffer
    {
        DirectX::XMMATRIX view;
    };

    struct PerObjectVSConstantBuffer
    {
        DirectX::XMMATRIX world;
    };

    BasicBitmapRenderSystem();
    virtual void Execute(double deltaTime) override;
private:
    virtual void AddEntity(Entity* pEntity) override;
    std::vector<Entity*> m_opaqueEntities;
    std::vector<Entity*> m_nonOpaqueEntities;
    void Render(Entity * pEntity, ID3D11DeviceContext* pDeviceContext, ID3D11Resource* pConstantBuffer);


    // Need to be filled in an effect

    void Initialize();
    ID3D11InputLayout* g_d3dInputLayout = nullptr;

    ID3D11VertexShader* g_d3dVertexShader = nullptr;

    ID3D11PixelShader* g_d3dPixelShader = nullptr;

    ID3D11SamplerState* g_d3dSamplerState = nullptr;

    Texture* m_pTexture = nullptr;

    enum ConstantBuffer
    {
        CB_Application, //The application level constant buffer stores variables that rarely change. 
        CB_Frame,       //The frame level constant buffer stores variables that change each frame. An example of a frame level shader variable would be the camera’s view matrix which changes whenever the camera moves
        CB_Object,      //The object level constant buffer stores variables that are different for every object being rendered. An example of an object level shader variable is the object’s world matrix.
        NumConstantBuffers
    };
    //three constant buffers: buffers are used to store shader variables that remain constant during current draw call. An example of a constant shader variable is the camera’s projection matrix. Since the projection matrix will be the same for every vertex of the object, this variable does not need to be passed to the shader using vertex data.

    ID3D11Buffer* g_d3dVSConstantBuffers[NumConstantBuffers];

    ID3D11Buffer* g_d3dPSConstantBuffer = nullptr;

    Game& game;
};

