#pragma once
#include "MeshComponentFactory.h"

enum class SphericalVisibility {
    VISIBLE_NONE,
    VISIBLE_FRONT,
    VISIBLE_BACK,           //not really necessary but why not
    VISIBLE_ALL
};

class SphericalMeshComponentFactory :
    public MeshComponentFactory
{
public:

    struct VertexData
    {
        DirectX::XMFLOAT4 Position;  //���������� ����� � ������������� ������������
        //DirectX::XMFLOAT4 Normal;
        //DirectX::XMFLOAT4 Tangent; //����� ��?
        DirectX::XMFLOAT2 TexCoord;
    };

    static MeshComponent* CreateSphericalSphere(double radius, int sliceCount, int stackCount);
    static MeshComponent* CreateSphericalPoint();
    static MeshComponent* CreateSphericalMeshFromFile(std::string fileName);
    //todo: �������� �� ������ ������ � ��������, �� � ��������� ������������ ������

private:
    static void SetVisibility();
};

