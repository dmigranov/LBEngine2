#include "pch.h"
#include "Texture.h"
#include "DDSTextureLoader.h"
#include "Game.h"
#include "ResourceManager.h"

Texture::Texture(const WCHAR* name)
{
	Game& game = Game::GetInstance();
	auto resourceManager = game.GetResourceManager();
	//*this = *resourceManager->CreateTexture(name);

	if (!this->Initialize(game.GetDevice(), name))
	{
		std::wstring ws1(L"Texture ");
		std::wstring ws2(name);
		std::wstring ws3(L" not found");
		auto errorMsg = ws1 + ws2 + ws3;
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)errorMsg.c_str(),
			(LPCWSTR)L"Resource not found",
			MB_ICONERROR
		);
	}
	resourceManager->AddTexture(this);
}

Texture::~Texture()
{
	Shutdown();
}

bool Texture::Initialize(ID3D11Device* device, const WCHAR* name)
{

	HRESULT result = DirectX::CreateDDSTextureFromFile(device, name, &m_resource, &m_texture); 
	if (FAILED(result))
	{
		return false;
	}
	ID3D11Texture2D* pTextureInterface = nullptr;
	m_resource->QueryInterface<ID3D11Texture2D>(&pTextureInterface);
	D3D11_TEXTURE2D_DESC desc;
	pTextureInterface->GetDesc(&desc);

	m_width = desc.Width;
	m_height = desc.Height;

	return true;
}

void Texture::Shutdown()
{
	if (m_texture)
	{
		m_texture->Release();
		m_texture = nullptr;
	}

	if (m_resource)
	{
		m_resource->Release();
		m_resource = nullptr;
	}

	return;
}

unsigned int Texture::GetWidth()
{
	return m_width;
}

unsigned int Texture::GetHeight()
{
	return m_height;
}

ID3D11ShaderResourceView* Texture::GetTexture()
{
	return m_texture;
}
