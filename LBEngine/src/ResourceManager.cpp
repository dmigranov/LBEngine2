#include "pch.h"
#include "ResourceManager.h"

#include "Texture.h"
#include "Game.h"

ResourceManager::ResourceManager(ID3D11Device* device)
{
    g_d3dDevice = device;
}

void ResourceManager::AddTexture(Texture* pTexture)
{
    textures.push_back(pTexture);
}

void ResourceManager::Clean()
{
    while (!textures.empty()) delete textures.front(), textures.pop_front();
}

// TODO: � ����� ��� ������ ResourceManager? ����� ��� ������ � ��������, � ��������� ����... 
// ���� ����� ����: ����� ������������� ������� ��������� �� ������� ������ Texture, ���������� �������