#include "InputManager.h"

InputManager::InputManager()
{
	m_input = 0;
	m_input_special = 0;
}

void InputManager::ListenInput() 
{
	if (kbhit()) { // 1. 키보드 입력이 감지되면
		int pressedKey = getch(); // 2. 아스키 코드 값을 가져오고
		this->m_input = pressedKey;
		if (pressedKey == 0 || pressedKey == 224) {
			this->m_input_special = pressedKey;
		}
	}
	else
		this->m_input = -1;
}

int InputManager::GetInput() 
{
	if (this->m_input == 0 || this->m_input == 224)
		return m_input_special;
	else
		return m_input;
}

bool InputManager::IsInputSpace(int input) 
{
	if (input == 32)
		return 1;
	else 
		return 0;
}

bool InputManager::IsInputUp(int input)
{
	if (input == 72 ||input ==119 ||input == 87)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputDown(int input)
{
	if (input == 80 || input == 115 || input == 83)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputLeft(int input)
{
	if (input == 75 || input == 97 || input == 65)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputRight(int input) // 77 (100, 68)
{
	if (input == 77 || input ==  100|| input == 68)
		return 1;
	else
		return 0;
}

bool InputManager::IsInputBoost(int input) // 102, 70
{
	if (input == 102 || input == 70 )
		return 1;
	else
		return 0;
}

bool InputManager::IsInputExit(int input)
{
	if (input == 27)
		return 1;
	else
		return 0;
}
