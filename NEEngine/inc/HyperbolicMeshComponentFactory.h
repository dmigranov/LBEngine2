#pragma once
#include "MeshComponentFactory.h"
class HyperbolicMeshComponentFactory :
    public MeshComponentFactory
{
public:
    struct VertexData
    {
        DirectX::XMFLOAT4 Position;
        //DirectX::XMFLOAT4 Normal;
        //DirectX::XMFLOAT4 Tangent; //����� ��?
        DirectX::XMFLOAT2 TexCoord;
    };

    static MeshComponent* CreateHyperbolicSphere(double radius, int sliceCount, int stackCount);
};

