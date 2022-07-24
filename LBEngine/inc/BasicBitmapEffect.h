#pragma once
#include "Effect.h"
class BasicBitmapEffect :
    public Effect
{
    struct PerApplicationVSConstantBuffer
    {
        DirectX::XMMATRIX proj;
        double density = 0.1;
        //double pad;
    };

    struct PerFrameVSConstantBuffer
    {
        DirectX::XMMATRIX view;
    };

    struct PerObjectVSConstantBuffer
    {
        DirectX::XMMATRIX world;
    };

    struct PerApplicationPSConstantBuffer
    {
        DirectX::XMVECTORF32 fogColor = DirectX::Colors::CadetBlue;
    };


};

