#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

//include required components

class GameManager {

private:
	ObjectManager m_ObjectManager;
	ObjectGenerator m_ObjectGenerator;
	InputManager m_InputManager;
	SceneManager m_SceneManager;

	int high_score;
	bool is_paused;

	void Ready();
	void Start();
	void Render();
	int DistanceToScore(float distance);
	void LoadHighScore();
	void SaveHighScore();
public:
	GameManager();

};

#endif