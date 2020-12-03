
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

//include required components

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

class InputManager {
private:
	int m_input;
	int m_input_special;
	bool is_up_pushed = false;
	bool is_down_pushed = false;
	bool is_left_pushed = false;
	bool is_right_pushed = false;
	bool is_space_pushed = false;
	bool is_f_pushed = false;
	bool is_esc_pushed = false;

	void Clear();
public:
	InputManager();
	void ListenInput();
	int GetInput();
	bool IsInputSpace();
	bool IsInputUp();
	bool IsInputDown();
	bool IsInputLeft();
	bool IsInputRight();
	bool IsInputBoost();
	bool IsInputExit();
};

#endif
