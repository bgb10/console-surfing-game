#include "SceneManager.h"

// Instantiates the SceneManager object
SceneManager::SceneManager() {
	size_x = 160;
	size_y = 45;
	center_x = 0.0f;
	center_y = 0.0f;
	nScreenIndex = 0;
}
// Instantiates with given width and height
SceneManager::SceneManager(int x, int y) {
	size_x = x;
	size_y = y;
	center_x = 0.0f;
	center_y = 0.0f;
	nScreenIndex = 0;
}
// create buffer
void SceneManager::CreateBuffer() {
	COORD size = { size_x, size_y };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;

	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = size_x - 1;
	rect.Top = size_y - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}
// write str at (x,y)
void SceneManager::WriteBuffer(int x, int y, std::string str) {
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);

	// string to const char*
	std::vector<char> temp_arr(str.begin(), str.end());
	temp_arr.push_back('\0');
	char* temp_arr_ptr = &temp_arr[0];

	WriteFile(hBuffer[nScreenIndex], temp_arr_ptr, strlen(temp_arr_ptr), &dw, NULL);
}
// Flip buffer
void SceneManager::FlipBuffer() {
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}
// Clear buffer
void SceneManager::ClearBuffer() {
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', size_x * size_y, Coor, &dw);
}
// Delete buffer
void SceneManager::DeleteBuffer() {
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
//Initialization
void SceneManager::Init() {

	// Set console_size
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", size_x, size_y);
	system(setText);

	// Set console_title
	SetConsoleTitle("Console surfing game");

	// Set cursor unvisible
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	// Create buffer
	CreateBuffer();
}
// Renders all object
void SceneManager::Render(ObjectManager& manager) {
	// Clear buffer
	ClearBuffer();

	// Get object from manager
	Player player = manager.GetPlayer();
	std::vector<MovableObject> movable_obj = manager.GetMovable();
	std::vector<GameObject> im = manager.GetImmovable();

	// Draw object

	// Flip buffer
	FlipBuffer();
}
// Finish the game
void SceneManager::Release() {
	this->DeleteBuffer();
}
// Set color
void SceneManager::SetColor(unsigned char BgColor, unsigned char TextColor){
	if (BgColor > 15 || TextColor > 15) return;

	unsigned short ColorNum = (BgColor << 4) | TextColor;
	SetConsoleTextAttribute(hBuffer[nScreenIndex], ColorNum);
}