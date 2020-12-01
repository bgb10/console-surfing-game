
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

//include required components

class InputManager {
private:
	int m_input;
	int m_input_special;
public:
	InputManager();
	void ListenInput();
	int GetInput();
	bool IsInputSpace(int input);
	bool IsInputUp(int input);
	bool IsInputDown(int input);
	bool IsInputLeft(int input);
	bool IsInputRight(int input);
	bool IsInputBoost(int input);
	bool IsInputExit(int input);
};


#endif
