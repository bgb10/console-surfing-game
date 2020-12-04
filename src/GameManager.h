#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

//include required components
#include "ObjectManager.h"
#include "ObjectGenerator.h"
#include "InputManager.h"
#include "SceneManager.h"

#include "GameObject/MovableObject/Player.h"

#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

class GameManager {

private:
	ObjectManager m_ObjectManager;
	ObjectGenerator m_ObjectGenerator;
	InputManager m_InputManager;
	SceneManager m_SceneManager;

	bool is_paused;
	bool is_start = false;

	system_clock::time_point curr;
	system_clock::time_point prev;

	void Ready();
	void Play();
	void Pause();
	void Update();
	void CleanGameObject();
	void DistanceToScore();
	int LoadHighScore();
	void SaveHighScore();

public:
	GameManager();
};

#endif