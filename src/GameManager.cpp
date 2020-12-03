#include "GameManager.h"

extern int score;
extern int boost_count;

void GameManager::Ready()
{
	// Generate default obstacles
	m_ObjectGenerator.Generate(m_ObjectManager);

	while (1)
	{
		m_SceneManager.Ready();

		if (m_InputManager.IsInputSpace())
		{
			m_ObjectManager.GetPlayer().SetVelocityY(1.0);
			
			return;
		}
	}
}

void GameManager::Play()
{
	is_paused = false;

	Player& player = m_ObjectManager.GetPlayer();

	while (1)
	{
		/* 1. Update objects and states according to input (from previous frame) */
		if (m_InputManager.IsInputUp())
		{
			player.Stop(); // stop the player character
		}
		else if (m_InputManager.IsInputDown())
		{
			player.ResetRotate(); // rotate to direct down
		}
		else if (m_InputManager.IsInputLeft())
		{
			player.RotateRight();
		}
		else if (m_InputManager.IsInputRight())
		{
			player.RotateLeft();
		}
		else if (m_InputManager.IsInputBoost())
		{
			if (boost_count > 0)
			{
				boost_count--;
				player.SetSpeedByFactor(1.5f); // 150% speed boost on use
			}
		}
		else if (m_InputManager.IsInputSpace())
		{
			Pause();
		}
		else if (m_InputManager.IsInputExit())
		{
			return; // exit game
		}
		else
		{
			//exception
		}

		// Generate entities
		m_ObjectGenerator.Generate(m_ObjectManager, m_SceneManager);
		
		Update();
	}
}

void GameManager::Pause()
{
	while (1)
	{
		m_SceneManager.Pause(m_ObjectManager);

		if (m_InputManager.IsInputSpace())
		{
			break;
		}
	}

	prev = system_clock::now();
}

void GameManager::Update()
{
	duration<double> elapsed;
	double delta;

	curr = system_clock::now();

	if (is_start == false)
	{
		is_start = true;
		delta = 0;
	}
	else
	{
		elapsed = curr - prev;
		delta = elapsed.count();
	}

	vector<MovableObject*>& vec_movable = m_ObjectManager.GetMovable();
	vector<GameObject*>& vec_immovable = m_ObjectManager.GetImmovable();
	Player& player = m_ObjectManager.GetPlayer();

	player.Move(delta);

	// move movable objects
	for (int id = 0; id < vec_movable.size(); id++)
	{
		vec_movable[id]->Move(delta);
	}

	// check collision between movable and player
	for (int id = 1; id < vec_movable.size(); id++)
	{
		if (vec_movable[id]->HasIntersected(player))
			vec_movable[id]->HitBy(player);
	}

	// check collision between immovable and player
	for (int id = 0; id < vec_immovable.size(); id++)
	{
		if (vec_immovable[id]->HasIntersected(player))
			vec_immovable[id]->HitBy(player);
	}

	DistanceToScore();
	m_SceneManager.Render(m_ObjectManager);
	prev = curr;
}

void GameManager::DistanceToScore()
{
	Player& player = m_ObjectManager.GetPlayer();

	float player_distance = sqrt(pow(player.GetCenterX(), 2) + pow(player.GetCenterY(), 2));

	// suggestion, multiply by factor to change the ratio between
	// in-game distance and user-visible distance
	score = (int)floor(player_distance);

	// update high score with new record
	if (high_score < score)
		high_score = score;
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
	m_SceneManager.Init();

	Ready();

	Play();
}