#include "pch.h"
#include "InputComponent.h"


KeyboardState InputComponent::GetKeyboardState()
{
	return m_keyboardState;
}

MouseState InputComponent::GetMouseState()
{
	return m_mouseState;
}

void InputComponent::SetInputData(DirectX::Keyboard::State keyboardState, DirectX::Mouse::State mouseState)
{
	this->m_keyboardState = keyboardState;
	this->m_mouseState = mouseState;
}

InputComponent::InputComponent()
{}