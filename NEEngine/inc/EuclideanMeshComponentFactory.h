#pragma once
#include "MeshComponentFactory.h"
class EuclideanMeshComponentFactory :
    public MeshComponentFactory
{
    struct VertexData
    {
        DirectX::XMFLOAT4 Position;
        //DirectX::XMFLOAT4 Normal;
        //DirectX::XMFLOAT4 Tangent; //����� ��?
        DirectX::XMFLOAT2 TexCoord;
    };

    static MeshComponent* CreateSphericalMeshFromFile(std::string fileName);
};

