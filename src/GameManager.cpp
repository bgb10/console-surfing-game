#include "GameManager.h"

void GameManager::Init()
{
	Ready();

	Play();
}

void GameManager::Ready()
{
	m_ObjectGenerator.GenerateDefaultObstacles(m_ObjectManager); // NEED

	m_SceneManager.Ready();
}

void GameManager::Play()
{
	bool is_paused = false;

	while (1)
	{
		m_ObjectGenerator.Generate(m_ObjectManager);

		m_InputManager.ListenInput();

		if (m_InputManager.IsInputUp())
		{
			m_ObjectManager.GetPlayer().SetVelocityX(0.0f);
			m_ObjectManager.GetPlayer().SetVelocityY(0.0f);
		}
		else if (m_InputManager.IsInputDown())
		{
			m_ObjectManager.GetPlayer().SetVelocityX(0.0f);
		}
		else if (m_InputManager.IsInputLeft())
		{
			m_ObjectManager.GetPlayer().MoveDirectionLeft(); // NEED
		}
		else if (m_InputManager.IsInputRight())
		{
			m_ObjectManager.GetPlayer().MoveDirectionRight; // NEED
		}
		else if (m_InputManager.IsInputBoost())
		{
			m_ObjectManager.GetPlayer().IncreaseSpeed(1.0f); // NEED
		}
		else if (m_InputManager.IsInputSpace())
		{
			is_paused = true;
		}
		else if (m_InputManager.IsInputExit())
		{
			// exit
			return;
		}
		else
		{
			//exception
		}

		if (is_paused)
		{
			m_SceneManager.Pause();
			is_paused = false;
		}
		else
		{
			Update();
			m_SceneManager.Render();
		}
	}
}

void GameManager::Update()
{
	double delta;

	time(&curr);

	if (prev == -1)
		delta = 0;
	else
		delta = difftime(curr, prev);
	
	m_ObjectManager.GetPlayer().SetCenter(
		m_ObjectManager.GetPlayer().GetCenterX() + delta * ratio * m_ObjectManager.GetPlayer().GetVelocityX(),
		m_ObjectManager.GetPlayer().GetCenterY() + delta * ratio * m_ObjectManager.GetPlayer().GetVelocityY(),
	);

	// collision detection

	m_SceneManager.Render();
	prev = curr;
}

int GameManager::DistanceToScore(float distance)
{
	float player_x = m_ObjectManager.GetPlayer().GetCenterX();
	float player_y = m_ObjectManager.GetPlayer().GetCenterY();

	float player_distance = sqrt(player_x * player_x + player_y * player_y);

	//초당 몇 칸을 움직이는가를 모르겠다.

}

int GameManager::LoadHighScore()
{
	std::ifstream in("highscore.dat");
	std::string s;

	if (in.is_open()) 
	{
		in >> s;
		high_score = std::stoi(s);
	}
	else
	{
		return 0;
	}

	return 1;
}

void GameManager::SaveHighScore()
{
	std::ofstream out("highscore.dat");
	
	if (out.is_open())
	{
		out << high_score;
	}

	return;
}

GameManager::GameManager()
{
	m_ObjectManager = ObjectManager();
	m_ObjectGenerator = ObjectGenerator();
	m_InputManager = InputManager();
	m_SceneManager = SceneManager();
}