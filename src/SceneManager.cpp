﻿#include "SceneManager.h"

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
// Draw texture
void SceneManager::Draw(float center_x, float center_y, int width, int height, std::string texture) {
	int x = round(center_x - (float)(width / 2));
	int y = round(center_y - (float)(height / 2));
	for (int i = 0; i < height; i++) {
		if (y + i < 0 || y + i >= size_y) continue;
		else if (x < 0) {
			for (int j = 0; j < width; j++) {
				if (x + j >= 0) {
					WriteBuffer(2 * (x + j), y + i, texture.substr(i*width + j, width - j));
					break;
				}
			}
		}
		else {
			int check = -1;
			for (int j = 0; j < width; j++) {
				if (x + j >= size_x / 2) {
					check = j;
					break;
				}
			}
			if (check == -1) {
				WriteBuffer(2 * x, y + i, texture.substr(i*width, width));
			}
			else {
				WriteBuffer(2 * x, y + i, texture.substr(i*width, check));
			}
		}
	}
}
// Initialize scene manager
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
// Print ready scene at console screen
void SceneManager::Ready() {
	// Clear buffer
	ClearBuffer();

	// Print UI
	std::string t;
	int health = 2;
	int high_score = 100;
	int boost = 3;
	t = "┌─────────────────────────────────────────┐";
	WriteBuffer(size_x / 2 - 22, 0, t);
	t = "│";
	WriteBuffer(size_x / 2 - 22, 1, t);
	for (int i = 0; i < 3; i++) {
		if (i < health) {
			t = "♥";
		}
		else {
			t = "♡";
		}
		WriteBuffer(size_x / 2 - 20 + 2 * i, 1, t);
	}
	t = "High score : " + std::to_string(high_score);
	WriteBuffer(size_x / 2 - 8, 1, t);
	t = "@";
	for (int i = 0; i < boost; i++) {
		WriteBuffer(size_x / 2 + 14 + 2 * i, 1, t);
	}
	t = "│";
	WriteBuffer(size_x / 2 + 20, 1, t);
	t = "└─────────────────────────────────────────┘";
	WriteBuffer(size_x / 2 - 22, 2, t);

	// Print player
	Player player = Player();
	Draw(size_x / 2, size_y / 2, player.GetWidth(), player.GetHeight(), player.GetTexture());

	// Flip buffer
	FlipBuffer();
}
// Print game scene at console screen
void SceneManager::Render(ObjectManager& manager) {
	// Clear buffer
	ClearBuffer();

	// Print UI
	std::string t;
	int health = 2;
	int high_score = 100;
	int boost = 3;
	t = "┌─────────────────────────────────────────┐";
	WriteBuffer(size_x / 2 - 22, 0, t);
	t = "│";
	WriteBuffer(size_x / 2 - 22, 1, t);
	for (int i = 0; i < 3; i++) {
		if (i < health) {
			t = "♥";
		}
		else {
			t = "♡";
		}
		WriteBuffer(size_x / 2 - 20 + 2 * i, 1, t);
	}
	t = "High score : " + std::to_string(high_score);
	WriteBuffer(size_x / 2 - 8, 1, t);
	t = "@";
	for (int i = 0; i < boost; i++) {
		WriteBuffer(size_x / 2 + 14 + 2 * i, 1, t);
	}
	t = "│";
	WriteBuffer(size_x / 2 + 20, 1, t);
	t = "└─────────────────────────────────────────┘";
	WriteBuffer(size_x / 2 - 22, 2, t);

	// Get object from manager
	Player player = manager.GetPlayer();
	std::vector<MovableObject> movable_obj = manager.GetMovable();
	std::vector<GameObject> immovable_obj = manager.GetImmovable();

	float dx, dy; // variables for coordinate calculation
	float x, y; // centerX, centerY
	int w, h; // width, height

	dx = size_x / 4 - player.GetCenterX();
	dy = size_y * 2 / 5 - player.GetCenterY();

	// Print immovable object
	for (int i = 0; i < immovable_obj.size(); i++) {
		x = immovable_obj[i].GetCenterX() + dx;
		y = immovable_obj[i].GetCenterY() + dy;
		w = immovable_obj[i].GetWidth();
		h = immovable_obj[i].GetHeight();
		t = immovable_obj[i].GetTexture();
		Draw(x, y, w, h, t);
	}

	// Print movable object
	for (int i = 0; i < movable_obj.size(); i++) {
		x = movable_obj[i].GetCenterX() + dx;
		y = movable_obj[i].GetCenterY() + dy;
		w = movable_obj[i].GetWidth();
		h = movable_obj[i].GetHeight();
		t = movable_obj[i].GetTexture();
		Draw(x, y, w, h, t);
	}

	// Print player
	Draw(size_x / 4, size_y * 2 / 5, player.GetWidth(), player.GetHeight(), player.GetTexture());
	
	
	// Flip buffer
	FlipBuffer();
}
// Print pause scene at console screen
void SceneManager::Pause() {
	// Clear buffer
	ClearBuffer();

	// Print UI
	std::string t;
	int health = 2;
	int high_score = 100;
	int boost = 3;
	t = "┌─────────────────────────────────────────┐";
	WriteBuffer(size_x / 2 - 22, 0, t);
	t = "│";
	WriteBuffer(size_x / 2 - 22, 1, t);
	for (int i = 0; i < 3; i++) {
		if (i < health) {
			t = "♥";
		}
		else {
			t = "♡";
		}
		WriteBuffer(size_x / 2 - 20 + 2 * i, 1, t);
	}
	t = "High score : " + std::to_string(high_score);
	WriteBuffer(size_x / 2 - 8, 1, t);
	t = "@";
	for (int i = 0; i < boost; i++) {
		WriteBuffer(size_x / 2 + 14 + 2 * i, 1, t);
	}
	t = "│";
	WriteBuffer(size_x / 2 + 20, 1, t);
	t = "└─────────────────────────────────────────┘";
	WriteBuffer(size_x / 2 - 22, 2, t);

	// Get object from manager
	Player player = manager.GetPlayer();
	std::vector<MovableObject> movable_obj = manager.GetMovable();
	std::vector<GameObject> immovable_obj = manager.GetImmovable();

	float dx, dy; // variables for coordinate calculation
	float x, y; // centerX, centerY
	int w, h; // width, height

	dx = size_x / 4 - player.GetCenterX();
	dy = size_y * 2 / 5 - player.GetCenterY();

	// Print immovable object
	for (int i = 0; i < immovable_obj.size(); i++) {
		x = immovable_obj[i].GetCenterX() + dx;
		y = immovable_obj[i].GetCenterY() + dy;
		w = immovable_obj[i].GetWidth();
		h = immovable_obj[i].GetHeight();
		t = immovable_obj[i].GetTexture();
		Draw(x, y, w, h, t);
	}

	// Print movable object
	for (int i = 0; i < movable_obj.size(); i++) {
		x = movable_obj[i].GetCenterX() + dx;
		y = movable_obj[i].GetCenterY() + dy;
		w = movable_obj[i].GetWidth();
		h = movable_obj[i].GetHeight();
		t = movable_obj[i].GetTexture();
		Draw(x, y, w, h, t);
	}

	// Print player
	Draw(size_x / 4, size_y * 2 / 5, player.GetWidth(), player.GetHeight(), player.GetTexture());

	// Print pause message
	t = "┌─────────────────────────┐";
	WriteBuffer(size_x / 2 - 14, 4, t);
	t = "│    게임이 일시 중지됨   │";
	WriteBuffer(size_x / 2 - 14, 5, t);
	t = "│                         │";
	WriteBuffer(size_x / 2 - 14, 6, t);
	t = "│   다시 시작하려면 space │";
	WriteBuffer(size_x / 2 - 14, 7, t);
	t = "└─────────────────────────┘";
	WriteBuffer(size_x / 2 - 14, 8, t);

	// Flip buffer
	FlipBuffer();
}
// Called when finish the game
void SceneManager::Release() {
	this->DeleteBuffer();
}
// Set background, texture color
void SceneManager::SetColor(unsigned char bg_color, unsigned char txt_color){
	if (bg_color > 15 || txt_color > 15) return;

	unsigned short ColorNum = (bg_color << 4) | txt_color;
	SetConsoleTextAttribute(hBuffer[nScreenIndex], ColorNum);
}