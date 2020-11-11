#pragma once
#include <string>

// Effect AKA Material. Abstraction for shaders, contains all the buffers and textures.
class Effect
{
public:
	//Effect - �������� ������ Mesh?
	//TODO: Effect - ���������/����������� ����� !!!
	//�� ����� �� ���� �������������, ��� �� ������ ������ � ����������� �� �� ������ �����
	//� ������� ���������� - ���� ����������� � ������� (����, �����)

	Effect();
	virtual ~Effect();
	void Initialize();
	void Deinitialize();
	void Update();
private:
	std::string		m_vsFileName;
	std::string		m_psFileName;

};

