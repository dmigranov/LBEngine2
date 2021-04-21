#include "pch.h"
#include "MeshComponent.h"

MeshComponent::MeshComponent(ID3D11Buffer* d3dVertexBuffer, ID3D11Buffer* d3dIndexBuffer, const std::type_info& vertexDataType, unsigned int indicesCount)
    : m_vertexDataType(vertexDataType), m_indicesCount(indicesCount)
{
    g_d3dVertexBuffer = d3dVertexBuffer;
    g_d3dIndexBuffer = d3dIndexBuffer;
}

Effect* MeshComponent::GetEffect() const
{
    return m_pEffect;
}

void MeshComponent::SetEffect(Effect* effect)
{
    m_pEffect = effect;
}

ID3D11Buffer * const MeshComponent::GetVertexBuffer()
{
    return g_d3dVertexBuffer;
}

ID3D11Buffer * const MeshComponent::GetIndexBuffer()
{
    return g_d3dIndexBuffer;
}

unsigned int MeshComponent::GetIndicesCount()
{
    return m_indicesCount;
}

MeshComponent::~MeshComponent()
{
    SafeRelease(g_d3dVertexBuffer);
    SafeRelease(g_d3dIndexBuffer);
}
