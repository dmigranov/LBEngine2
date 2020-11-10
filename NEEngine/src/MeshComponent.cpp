#include "pch.h"
#include "MeshComponent.h"

#include "Game.h"


MeshComponent::MeshComponent(int nv, VertexPosTex* vertices, int ni, WORD* indices)
{
	auto& game = Game::GetInstance();
	auto device = game.g_d3dDevice;
	deviceContext = game.g_d3dDeviceContext;
	d3dConstantBuffer = game.g_d3dVSConstantBuffers[2];
	g_Indices = indices;
	g_Vertices = vertices;
	verticesCount = nv;
	indicesCount = ni;

	// Create and initialize the vertex buffer.
	D3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(D3D11_BUFFER_DESC));

	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;  //how the buffer is bound to pipeline
	vertexBufferDesc.ByteWidth = sizeof(VertexPosTex) * verticesCount;
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

void MeshComponent::Render(DirectX::XMMATRIX world)
{
	const UINT vertexStride = sizeof(VertexPosTex);   //Each stride is the size (in bytes) of the elements that are to be used from that vertex buffer.
	const UINT offset = 0;
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	deviceContext->IASetVertexBuffers(0, 1, &g_d3dVertexBuffer, &vertexStride, &offset);
	deviceContext->IASetIndexBuffer(g_d3dIndexBuffer, DXGI_FORMAT_R16_UINT, 0);

	if (m_pTexture != nullptr)
	{     //Pixel Shader Stafe - unique 4 every stage
		auto shaderResource = m_pTexture->GetTexture();
		deviceContext->PSSetShaderResources(0, 1, &shaderResource);
	}

	deviceContext->UpdateSubresource(d3dConstantBuffer, 0, nullptr, &world, 0, 0);

	//DRAW
	deviceContext->DrawIndexed(indicesCount, 0, 0);
}

MeshComponent::~MeshComponent()
{
	SafeRelease(g_d3dVertexBuffer);
	SafeRelease(g_d3dIndexBuffer);
}

void MeshComponent::SetTexture(Texture* texture)
{
	this->m_pTexture = texture;
}