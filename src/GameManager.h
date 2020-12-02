#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

//include required components
#include "ObjectManager.h";
#include "ObjectGenerator.h"
#include "InputManager.h"
#include "SceneManager.h"

#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

#define ratio 0.1


class GameManager {

private:
	ObjectManager m_ObjectManager;
	ObjectGenerator m_ObjectGenerator;
	InputManager m_InputManager;
	SceneManager m_SceneManager;

	int high_score;
	bool is_paused;

	time_t curr, prev = -1;

	void Init();
	void Ready();
	void Start();
	void Update();
	int DistanceToScore(float distance);
	int LoadHighScore();
	void SaveHighScore();

public:
	GameManager();

};

#endif