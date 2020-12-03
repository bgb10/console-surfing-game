#include "InputManager.h"

InputManager::InputManager()
{
	m_input = 0;
	m_input_special = 0;
}

void InputManager::ListenInput()
{
	if (_kbhit()) { // 1. 키보드 입력이 감지되면
		int pressedKey = _getch(); // 2. 아스키 코드 값을 가져오고
		this->m_input = pressedKey;
		if (pressedKey == 0 || pressedKey == 224) {
			this->m_input_special = _getch();
		}
	}
	else
		this->m_input = -1;
}

int InputManager::GetInput()
{
	if (this->m_input == 0 || this->m_input == 224)
	{
		return m_input_special;
	}
	else
		return m_input;
}

void InputManager::Clear()
{
	m_input = 0;
	m_input_special = 0;
}

bool InputManager::IsInputSpace()
{
	if (this->m_input == 32)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputUp()
{
	int input = this->m_input;
	if (input == 119 || input == 87)
		return 1;
	else
		if ((input == 0 || input == 224) && (this->m_input_special == 72))
			return 1;
		else
			return 0;
}

bool InputManager::IsInputDown()
{
	int input = this->m_input;
	if (input == 115 || input == 83)
		return 1;
	else
		if ((input == 0 || input == 224) && (this->m_input_special == 80))
			return 1;
		else
			return 0;
}

bool InputManager::IsInputLeft()
{
	int input = this->m_input;
	if (input == 97 || input == 65)
		return 1;
	else
		if ((input == 0 || input == 224) && (this->m_input_special == 75))
			return 1;
		else
			return 0;
}

bool InputManager::IsInputRight() // 77 (100, 68)
{
	int input = this->m_input;
	if (input == 100 || input == 68)
		return 1;
	else
		if ((input == 0 || input == 224) && (this->m_input_special == 77))
			return 1;
		else
			return 0;
}

bool InputManager::IsInputBoost() // 102, 70
{
	int input = this->m_input;
	if (input == 102 || input == 70)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputExit()
{
	int input = this->m_input;
	if (input == 27)
		return 1;
	else
		return 0;
}
