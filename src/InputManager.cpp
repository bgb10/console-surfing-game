#include "InputManager.h"

InputManager::InputManager()
{
	m_input = 0;
	m_input_special = 0;
}

void InputManager::ListenInput()
{
	/*
	if (_kbhit()) { // 1. 키보드 입력이 감지되면
		int pressedKey = _getch(); // 2. 아스키 코드 값을 가져오고
		this->m_input = pressedKey;
		if (pressedKey == 0 || pressedKey == 224) {
			this->m_input_special = _getch();
		}
	}
	else
		this->m_input = -1;
	*/
}

int InputManager::GetInput()
{
	/*
	if (this->m_input == 0 || this->m_input == 224)
	{
		return m_input_special;
	}
	else
		return m_input;
	*/

	return 0;
}

void InputManager::Clear()
{
	is_up_pushed = false;
	is_down_pushed = false;
	is_left_pushed = false;
	is_right_pushed = false;
	is_space_pushed = false;
	is_f_pushed = false;
	is_esc_pushed = false;
}

bool InputManager::IsInputSpace()
{
	if (GetAsyncKeyState(VK_SPACE) & (0x8001 == 0x8001)) return 1;
	else return 0;
}

bool InputManager::IsInputUp()
{
	if (GetAsyncKeyState(VK_UP) & (0x8001 == 0x8001)) return 1;
	else return 0;
}

bool InputManager::IsInputDown()
{
	if (GetAsyncKeyState(VK_DOWN) & (0x8001 == 0x8001)) return 1;
	else return 0;
}

bool InputManager::IsInputLeft()
{
	if (GetAsyncKeyState(VK_LEFT) & (0x8001 == 0x8001)) return 1;
	else return 0;
}

bool InputManager::IsInputRight() // 77 (100, 68)
{
	if (GetAsyncKeyState(VK_RIGHT) & (0x8001 == 0x8001)) return 1;
	else return 0;
}

bool InputManager::IsInputBoost() // 102, 70
{
	bool key_down = false;
	while (GetAsyncKeyState(0x46) & (0x8001 == 0x8001)) key_down = true;
	if (key_down == true) return 1;
	else return 0;
}

bool InputManager::IsInputExit()
{
	if (GetAsyncKeyState(VK_ESCAPE) & (0x8001 == 0x8001)) return 1;
	else return 0;
}