#pragma once

#include "Texture.h"
#include <wtypes.h>

#include "Component.h"
#include "MeshComponent.h"

struct VertexPosTex //todo: �������������
{
    DirectX::XMFLOAT4 Position;  //���������� ����� � ������������� ������������
    DirectX::XMFLOAT2 TexCoord;
};

class VertexTexMeshComponentDel
{
public:

    VertexTexMeshComponentDel(int nv, VertexPosTex* vertices, int ni, WORD* indices);
};
