#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

class SceneManager {
private:
	int size_x; // width of the console window
	int size_y; // height of the console window
	float center_x; // x-axis position of the camera
	float center_y; // y-axis position of the camera
	HANDLE hBuffer[2]; // buffer handle
	int nScreenIndex; // save current buffer
	void CreateBuffer(); // create buffer
	void WriteBuffer(int x, int y, std::string str); // write str at (x,y)
	void FlipBuffer(); // Flip buffer
	void ClearBuffer(); // Clear buffer
	void DeleteBuffer(); // Delete buffer
public:
	SceneManager(); // Instantiates the SceneManager object
	SceneManager(int x, int y); // Instantiates with given width and height
	void Init(); // Initialization
	void Render(ObjectManager& manager); // Renders all object
	void Release(); // Finish the game
	void SetColor(unsigned char BgColor, unsigned char TextColor); // Set color
};

#endif