#pragma once
#include <string>

class Entity;

//todo: �������� RENDER MAP ��� ������������ ���������� 
//� ��������� � �������������� � ��������

// Effect AKA Material. Abstraction for shaders, contains all the buffers and textures.
// Each entity has an effect?
// Or should each mesh have an effect?
// Any way, effects depend on stuff like transforms...
class Effect
{
public:
	// Effect - ����������� �����
	// �� ����� �� ���� �������������, 
	// � ���������� �� ������ ������ � ����������� �� �� ������ �����
	// � ������� ���������� - ���� ����������� � ������� (����, �����)
	
	// � ������� ���������� ������ �������� 
	// (todo: ����� �� ��� ������� ���-�� �������������? ����� � ����. ������ ���-�� ����, ��� ������� ���������� ����?)
	// � Mesh ��������� ������ � ����� <Struct>
	
	Effect();
	virtual ~Effect();
	virtual bool Initialize() = 0;

	virtual void UpdatePerObject(const Entity* pEntity) = 0;
	virtual void UpdatePerScene() = 0;
	virtual void UpdatePerApplication() = 0; //todo: ��������� ��� - ��� �����������

	virtual unsigned int GetVertexBufferSize() const = 0;

	virtual void Deinitialize() = 0;

	virtual const std::type_info& GetVertexDataType() = 0;
	virtual std::string GetName();
	bool IsInited();

protected: 
	bool m_isInited = false;
	std::string magic;



};

