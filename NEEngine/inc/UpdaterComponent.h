#pragma once
#include "Component.h"

class UpdaterComponent :
    public Component
{
    //todo: ��������� ������ (�����, ������ ���������� ���� ������?)
    //��� ������ TransfComp?
public:
    UpdaterComponent(std::function<void(double delta)> func);
    void operator()(double delta);
private:
    std::function<void(double delta)> m_func;
};

