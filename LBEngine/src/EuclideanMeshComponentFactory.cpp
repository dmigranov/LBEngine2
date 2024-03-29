#include "pch.h"
#include "EuclideanMeshComponentFactory.h"

#include "MeshComponent.h"
#include "Game.h"

#include <atlbase.h>
#include <atlconv.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

MeshComponent* EuclideanMeshComponentFactory::CreateSphere(double radius, int sliceCount, int stackCount)
{
    auto phiStep = XM_PI / stackCount;
    auto thetaStep = XM_2PI / sliceCount;

    std::vector<VertexData> vertices;
    std::vector<WORD> indices;

    vertices.push_back({ XMFLOAT4(0.f, radius, 0.f, 1.f),
        //XMFLOAT4(0.f, 1.f, 0.f, 0.f),     //normal
        XMFLOAT2(0.f, 0.f) });	//North pole

    for (int i = 1; i <= stackCount - 1; i++) {
        auto phi = i * phiStep;
        for (int j = 0; j <= sliceCount; j++) {
            auto theta = j * thetaStep;
            XMFLOAT4 pos(
                (radius * sinf(phi) * cosf(theta)),
                (radius * cosf(phi)),
                (radius * sinf(phi) * sinf(theta)),
                1.f
            );

            auto uv = XMFLOAT2(theta / XM_2PI, phi / XM_PI);
            vertices.push_back({ pos,
                //pos.Normalize(���������)
                uv });
        }
    }

    vertices.push_back({ XMFLOAT4(0.f, -radius, 0.f, 1.f),
        //XMFLOAT4(0.f, -1.f, 0.f, 0.f),    //normal
        XMFLOAT2(0.f, 1.f) }); //south pole

    //INDICES

    WORD northPoleIndex = 0;
    for (int i = 1; i <= sliceCount; i++) {
        indices.push_back(northPoleIndex);
        indices.push_back(i + 1);
        indices.push_back(i);
    }

    WORD baseIndex = 1;
    WORD ringVertexCount = sliceCount + 1;
    for (int i = 0; i < stackCount - 2; i++) {
        for (int j = 0; j < sliceCount; j++) {
            indices.push_back(baseIndex + i * ringVertexCount + j);
            indices.push_back(baseIndex + i * ringVertexCount + j + 1);
            indices.push_back(baseIndex + (i + 1) * ringVertexCount + j);

            indices.push_back(baseIndex + (i + 1) * ringVertexCount + j);
            indices.push_back(baseIndex + i * ringVertexCount + j + 1);
            indices.push_back(baseIndex + (i + 1) * ringVertexCount + j + 1);
        }
    }

    WORD southPoleIndex = vertices.size() - 1;
    baseIndex = southPoleIndex - ringVertexCount;
    for (int i = 0; i < sliceCount; i++) {
        indices.push_back(southPoleIndex);
        indices.push_back(baseIndex + i);
        indices.push_back(baseIndex + i + 1);
    }

    auto g_Vertices = &vertices[0];
    auto verticesCount = vertices.size();

    auto g_Indices = &indices[0];
    auto indicesCount = indices.size();

    return MeshComponentFactory::CreateMeshComponent<VertexData>(verticesCount, g_Vertices, indicesCount, g_Indices);;
}

MeshComponent* EuclideanMeshComponentFactory::CreateCube(double side)
{
    return CreateRectangularCuboid(side, side, side);
}

MeshComponent* EuclideanMeshComponentFactory::CreateRectangularCuboid(double xSide, double ySide, double zSide)
{
    auto xCoord = xSide / 2;
    auto yCoord = ySide / 2;
    auto zCoord = zSide / 2;

    VertexData vertices[] = {
        //front:
        { XMFLOAT4(-xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(1.f / 3, 1.f) }, // 0
        { XMFLOAT4(-xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(1.f / 3, 0.5f)  }, // 1
        { XMFLOAT4(xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(2.f / 3, 1.f)   }, // 2
        { XMFLOAT4(xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(2.f / 3, 0.5f)  }, // 3

        //left:
        { XMFLOAT4(-xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(2.f / 3, 0.5f) }, // 4
        { XMFLOAT4(-xCoord,  -yCoord, zCoord, 1),   XMFLOAT2(1.f / 3, 0.5f) }, // 5
        { XMFLOAT4(-xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(2.f / 3, 0.f)}, // 6
        { XMFLOAT4(-xCoord,  yCoord, zCoord, 1),  XMFLOAT2(1.f / 3, 0.f)  }, // 7

        //right:
        { XMFLOAT4(xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(0.f, 0.5f)   }, // 8
        { XMFLOAT4(xCoord,  yCoord, zCoord, 1),  XMFLOAT2(1.f / 3, 0.f)   }, // 9
        { XMFLOAT4(xCoord,  -yCoord, zCoord, 1),  XMFLOAT2(1.f / 3, 0.5f)  }, // 10
        { XMFLOAT4(xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(0.f, 0.f)  }, // 11

        //top:
        { XMFLOAT4(-xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(2.f / 3, 0.5f)  }, // 12
        { XMFLOAT4(-xCoord,  yCoord, zCoord, 1),  XMFLOAT2(2.f / 3, 0.f)  }, // 13
        { XMFLOAT4(xCoord,  yCoord, zCoord, 1),  XMFLOAT2(1.f, 0.f)   }, // 14
        { XMFLOAT4(xCoord,  yCoord, -zCoord, 1),  XMFLOAT2(1.f, 0.5f)  }, // 15

        //bottom:
        { XMFLOAT4(-xCoord,  -yCoord, zCoord, 1),  XMFLOAT2(0.f, 1.f)   }, // 16
        { XMFLOAT4(-xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(0.f, 0.5f) }, // 17
        { XMFLOAT4(xCoord,  -yCoord, -zCoord, 1),  XMFLOAT2(1.f / 3, 0.5f) }, // 18
        { XMFLOAT4(xCoord,  -yCoord, zCoord, 1),  XMFLOAT2(1.f / 3, 1.f)  }, // 19

        //back:
        { XMFLOAT4(xCoord,  yCoord, zCoord, 1),  XMFLOAT2(2.f / 3, 0.5f)  }, // 20
        { XMFLOAT4(-xCoord,  yCoord, zCoord, 1),  XMFLOAT2(1.f, 0.5f)  }, // 21
        { XMFLOAT4(-xCoord,  -yCoord, zCoord, 1),  XMFLOAT2(1.f, 1.f)  }, // 22
        { XMFLOAT4(xCoord,  -yCoord, zCoord, 1),  XMFLOAT2(2.f / 3, 1.f)   }, // 23
    };

    auto verticesCount = _countof(vertices);

    WORD indices[] = {
            0, 1, 2,
            2, 1, 3, 

            4, 5, 6,
            7, 6, 5, 

            8, 9, 10,
            8, 11, 9,

            12, 13, 14,
            12, 14, 15, 

            16, 17, 18,
            16, 18, 19, 

            20, 21, 22,
            23, 20, 22 
    };

    auto indicesCount = _countof(indices);

    return MeshComponentFactory::CreateMeshComponent<VertexData>(verticesCount, vertices, indicesCount, indices);
}

MeshComponent* EuclideanMeshComponentFactory::CreateMeshFromFile(std::string filepath)
{
    std::ifstream infile;
    infile.open(filepath);

    if (!infile)
    {
        //std::cerr << "Unable to open file " << filepath << std::endl;
        std::string msg = "Unable to open file " + filepath; 
        CA2W unicodeMsg(msg.c_str());
        int msgboxID = MessageBox(
            NULL,
            unicodeMsg,
            unicodeMsg,
            MB_ICONERROR
        );
        return nullptr;
    }

    std::string str;

    std::vector<VertexData> vertices;
    std::vector<WORD> vertexIndices;

    std::vector<Vector4> positions;
    std::vector<int> positionIndices;

    std::vector<Vector2> uv0;
    std::vector<int> textureIndices;

    while (std::getline(infile, str))
    {
        if (str[0] == 'v')
        {
            if (str[1] == ' ') //v -0.5 0.5 -0.5 1
            {
                str = str.substr(2);
                std::vector<std::string> parsedStrings = parseString(str, ' ');
                std::vector<double> values = getDoubleValues(parsedStrings);

                double w;
                if (values.size() < 3)
                    return nullptr; //todo
                else if (values.size() < 4)
                    w = 1.;
                else
                    w = values[3];

                positions.push_back(Vector4(values[0], values[1], values[2], w));
            }
            else if (str[1] == 't') //vt 0 0
            {
                str = str.substr(3);
                std::vector<std::string> parsedStrings = parseString(str, ' ');
                std::vector<double> values = getDoubleValues(parsedStrings);
                if (values.size() < 2)
                    return nullptr; //todo

                uv0.push_back(Vector2(values[0], values[1]));
            }
        }
        else if (str[0] == 'f') //f 2/2 4/4 1/1
        {
            str = str.substr(2);
            std::vector<std::string> parsedStrings = parseString(str, ' ');
            if (parsedStrings.size() < 3)
                return nullptr; //todo

            for (std::string substr : parsedStrings) //2/2
            {
                std::vector<std::string> strIndices = parseString(substr, '/');
                std::vector<int> indices = getIntValues(strIndices);
                if (indices.size() < 2)
                    return nullptr; //todo

                positionIndices.push_back(indices[0] - 1); //������� ��������� � �������, � �� � ����
                textureIndices.push_back(indices[1] - 1);
            }
        }
    }

    for (int i = 0; i < positionIndices.size(); i++)
    {
        auto posIndex = positionIndices[i];
        auto texIndex = textureIndices[i];

        VertexData vpc = { positions[posIndex], uv0[texIndex] };
        vertices.push_back(vpc);
        vertexIndices.push_back(i);
    }

    return MeshComponentFactory::CreateMeshComponent<VertexData>(vertices.size(), &vertices[0], vertexIndices.size(), &vertexIndices[0]);
}

std::vector<std::string> EuclideanMeshComponentFactory::parseString(std::string str, char delimiter)
{
    std::vector<std::string> vec;
    size_t startIndex = 0;
    size_t endIndex;
    while ((endIndex = str.find(delimiter, startIndex)) != std::string::npos)
    {
        std::string substr = str.substr(startIndex, endIndex - startIndex);
        vec.push_back(substr);
        startIndex = endIndex + 1;
    }
    std::string substr = str.substr(startIndex, endIndex - startIndex);
    vec.push_back(substr);
    return vec;
}

std::vector<double> EuclideanMeshComponentFactory::getDoubleValues(std::vector<std::string> strings)
{
    std::vector<double> vec;
    for (std::string str : strings)
    {
        vec.push_back(atof(str.c_str()));
    }
    return vec;
}

std::vector<int> EuclideanMeshComponentFactory::getIntValues(std::vector<std::string> strings)
{
    std::vector<int> vec;
    for (std::string str : strings)
    {
        vec.push_back(atoi(str.c_str()));
    }
    return vec;
}
