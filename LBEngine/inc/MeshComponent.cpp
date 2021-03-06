#include "pch.h"
#include "MeshComponent.h"
#include "Effect.h"

MeshComponent::MeshComponent(ID3D11Buffer* d3dVertexBuffer, ID3D11Buffer* d3dIndexBuffer, const std::type_info& vertexDataType, unsigned int indicesCount, D3D_PRIMITIVE_TOPOLOGY topology)
    : m_vertexDataType(vertexDataType), m_indicesCount(indicesCount)
{
    g_d3dVertexBuffer = d3dVertexBuffer;
    g_d3dIndexBuffer = d3dIndexBuffer;
    m_topology = topology;
    m_pEffect = nullptr;
}

Effect* MeshComponent::GetEffect() const
{
    return m_pEffect;
}

void MeshComponent::SetEffect(Effect* effect)
{
    if (effect->GetVertexDataType() != this->GetVertexDataType())
        std::cerr << "Different (perhaps incompatible, but maybe not) data type for effect " << effect->GetName() << "; perhaps you should check it out!" << std::endl; //todo: ??? entity?
    m_pEffect = effect;
}

ID3D11Buffer * MeshComponent::GetVertexBuffer() const
{
    return g_d3dVertexBuffer;
}

ID3D11Buffer * MeshComponent::GetIndexBuffer() const
{
    return g_d3dIndexBuffer;
}

D3D_PRIMITIVE_TOPOLOGY MeshComponent::GetTopology() const
{
    return m_topology;
}

unsigned int MeshComponent::GetIndicesCount()
{
    return m_indicesCount;
}

const std::type_info& MeshComponent::GetVertexDataType()
{
    return m_vertexDataType;
}

MeshComponent::~MeshComponent()
{
    SafeRelease(g_d3dVertexBuffer);
    SafeRelease(g_d3dIndexBuffer);
}
