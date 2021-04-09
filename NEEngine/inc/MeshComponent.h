#pragma once
#include "AbstractMeshComponent.h"

class Game;

//todo: ������ ������, �������� ������ �� MeshComponentFactory

template <class VertexData>
class MeshComponent : public AbstractMeshComponent
{
public:
	MeshComponent(int nv, VertexData* vertices, int ni, WORD* indices);

	virtual ~MeshComponent();
protected:
	VertexData* g_Vertices;
	int verticesCount;
	WORD* g_Indices;

};

template<class VertexData>
inline MeshComponent<VertexData>::MeshComponent(int nv, VertexData* vertices, int ni, WORD* indices)
{
	auto& game = Game::GetInstance();
	auto device = game.GetDevice();
	deviceContext = game.GetDeviceContext();
	g_Indices = indices;
	g_Vertices = vertices;
	verticesCount = nv;
	indicesCount = ni;

	// Create and initialize the vertex buffer.
	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));

	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;  //how the buffer is bound to pipeline
	vertexBufferDesc.ByteWidth = sizeof(VertexData) * verticesCount;
	vertexBufferDesc.CPUAccessFlags = 0;    // no CPU access is necessary
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

	//used to specify the data that is used to initialize a buffer when it is created.
	D3D11_SUBRESOURCE_DATA resourceData;
	ZeroMemory(&resourceData, sizeof(D3D11_SUBRESOURCE_DATA));
	resourceData.pSysMem = g_Vertices; //A pointer to the data to initialize the buffer with.

	device->CreateBuffer(&vertexBufferDesc, &resourceData, &g_d3dVertexBuffer);

	// Create and initialize the index buffer.
	D3D11_BUFFER_DESC indexBufferDesc;
	ZeroMemory(&indexBufferDesc, sizeof(D3D11_BUFFER_DESC));

	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.ByteWidth = sizeof(WORD) * indicesCount;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	resourceData.pSysMem = g_Indices;

	device->CreateBuffer(&indexBufferDesc, &resourceData, &g_d3dIndexBuffer);
}

template<class VertexData>
inline MeshComponent<VertexData>::~MeshComponent()
{
	SafeRelease(g_d3dVertexBuffer);
	SafeRelease(g_d3dIndexBuffer);
}