#include "GameManager.h"

extern int score;
extern int life_count;
extern int boost_count;
extern int high_score;

void GameManager::Ready()
{
	// Initialize
	m_ObjectManager.Clear();
	m_ObjectManager.GetPlayer().SetCenter(0, 0);
	m_ObjectManager.GetPlayer().SetInvincibleDistance(-1.0f);

	// Generate default obstacles
	m_ObjectGenerator.Generate(m_ObjectManager);

	// Display ready scene
	m_SceneManager.Ready();

	while (1)
	{
		if (m_InputManager.IsInputSpace())
		{
			m_ObjectManager.GetPlayer().SetVelocityY(1.0);
			
			return;
		}
		if (m_InputManager.IsInputExit()) {
			exit = true;
			return;
		}
	}
}

void GameManager::Play()
{

	Player& player = m_ObjectManager.GetPlayer();

	while (1)
	{
		if (life_count > 0)
		{
			/* 1. Update objects and states according to input (from previous frame) */
			if (m_InputManager.IsInputUp())
			{
				player.Stop(); // stop the player character
			}
			if (m_InputManager.IsInputDown())
			{
				player.ResetRotate(); // rotate to direct down

				if (player.GetVelocityY() == 0 && life_count > 0)
					player.SetVelocityY(1.0f); // resume player when stopped
			}
			if (m_InputManager.IsInputLeft())
			{
				player.RotateRight();
			}
			if (m_InputManager.IsInputRight())
			{
				player.RotateLeft();
			}
			if (m_InputManager.IsInputBoost())
			{
				if (boost_count > 0)
				{
					boost_count--;
					player.SetSpeedByFactor(1.5f); // 150% speed boost on use
				}
			}
			if (m_InputManager.IsInputSpace())
			{
				Pause();
			}
			if (m_InputManager.IsInputExit())
			{
				return; // exit game
			}

			// Generate entities
			if(player.GetVelocityY() > 0.5f) m_ObjectGenerator.Generate(m_ObjectManager, m_SceneManager);

			Update();
		}
		else
		{
			m_SceneManager.GameOver(m_ObjectManager);
			if (m_InputManager.IsInputSpace())
			{
				life_count = 3;
				boost_count = 0;
				score = 0;
				is_start = false;
				break;
			}
		}
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

	player.SetSpeed();
	player.Move(delta);

	// move movable objects
	for (int id = 0; id < vec_movable.size(); id++)
	{
		vec_movable[id]->Move(delta);
	}

	// check collision between movable and player
	for (int i = 0; i < vec_movable.size(); i++)
	{
		if (!player.CheckInvincible())
		{
			if (vec_movable[i]->GameObject::IsVisible())
			{
				if (vec_movable[i]->HasIntersected(player))
					vec_movable[i]->HitBy(&player);
			}
			else
				m_ObjectManager.RemoveMovable(vec_movable[i]);
		}
	}

	// check collision between movable and immovable
	for (int i = 0; i < vec_immovable.size(); i++)
	{
		for (int j = 0; j < vec_movable.size(); j++)
		{
			if (vec_immovable[i]->GameObject::IsVisible())
			{
				if (vec_immovable[i]->HasIntersected(*vec_movable[j]))
					vec_immovable[i]->HitBy(vec_movable[j]);
			}
			else
				m_ObjectManager.RemoveImmovable(vec_movable[j]);
		}
	}

	// check collision between immovable and player
	for (int i = 0; i < vec_immovable.size(); i++)
	{
		if (vec_immovable[i]->GameObject::IsVisible())
		{
			if (vec_immovable[i]->HasIntersected(player))
				vec_immovable[i]->HitBy(&player);
		}
		else
			m_ObjectManager.RemoveImmovable(vec_immovable[i]);
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

	while (1)
	{
		LoadHighScore();

		Ready();

		if (exit) {
			return;
		}

		Play();

		SaveHighScore();
	}
}