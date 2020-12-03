#include "GameManager.h"

extern int score;
extern int boost_count;

void GameManager::Init()
{
	Ready();

	Play();
}

void GameManager::Ready()
{
	// Generate default obstacles
	m_ObjectGenerator.Generate(m_ObjectManager);

	m_SceneManager.Ready();
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
			player.RotateLeft();
		}
		else if (m_InputManager.IsInputRight())
		{
			player.RotateRight();
		}
		else if (m_InputManager.IsInputBoost())
		{
			if (boost_count > 0)
			{
				player.SetSpeedByFactor(1.5f); // 150% speed boost on use
				boost_count--;
			}
		}
		else if (m_InputManager.IsInputSpace())
		{
			is_paused = !is_paused; // invert the pause state
		}
		else if (m_InputManager.IsInputExit())
		{
			return; // exit game
		}
		else
		{
			//exception
		}

		/* 2. Listen for inputs in the next frame */
		m_InputManager.ListenInput();

		/* 3. Calculate and render frame */

		// Generate entities
		m_ObjectGenerator.Generate(m_ObjectManager, m_SceneManager);
		
		// Pause screen if pause state is true
		if (is_paused)
			m_SceneManager.Pause(m_ObjectManager);
		else
			Update();

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

	vector<MovableObject>& vec_movable = m_ObjectManager.GetMovable();
	vector<GameObject>& vec_immovable = m_ObjectManager.GetImmovable();
	Player& player = m_ObjectManager.GetPlayer();

	// move movable objects
	for (int id = 0; id < vec_movable.size(); id++)
	{
		vec_movable[id].Move(delta);
	}

	// check collision between movable and player
	for (int id = 1; id < vec_movable.size(); id++)
	{
		vec_movable[id].HitBy(player);
	}

	// check collision between immovable and player
	for (int id = 0; id < vec_immovable.size(); id++)
	{
		vec_immovable[id].HitBy(player);
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
	score = floor(player_distance);

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
	// C++ doesn't need explicit instantiation

	// m_ObjectManager = ObjectManager();
	// m_ObjectGenerator = ObjectGenerator();
	// m_InputManager = InputManager();
	// m_SceneManager = SceneManager();

	// TODO: Merge Init() and GameManager() if they do the same thing
	Init();
}