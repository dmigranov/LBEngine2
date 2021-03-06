#pragma once
#include "MeshComponentFactory.h"
class EuclideanMeshComponentFactory :
    public MeshComponentFactory
{
public:
    struct VertexData
    {
        DirectX::XMFLOAT4 Position;
        //DirectX::XMFLOAT4 Normal;
        //DirectX::XMFLOAT4 Tangent; //????? ???
        DirectX::XMFLOAT2 TexCoord;
    };

    static MeshComponent* CreateSphere(double radius, int sliceCount = 30, int stackCount = 30);
    static MeshComponent* CreateCube(double side);
    static MeshComponent* CreateRectangularCuboid(double xSide, double ySide, double zSide);

    static MeshComponent* CreateMeshFromFile(std::string fileName);

private:
    static std::vector<std::string> parseString(std::string str, char delimiter);
    static std::vector<double> getDoubleValues(std::vector<std::string> strings);
    static std::vector<int> getIntValues(std::vector<std::string> strings);
};

