#include "GameManager.h"

void GameManager::Ready()
{

}

void GameManager::Start()
{

}

void GameManager::Render()
{

}

int GameManager::DistanceToScore(float distance)
{
	float player_x = m_ObjectManager.GetPlayer().GetCenterX();
	float player_y = m_ObjectManager.GetPlayer().GetCenterY();

	float player_distance = sqrt(player_x * player_x + player_y * player_y);

	//초당 몇 칸을 움직이는가?

}

void GameManager::LoadHighScore()
{

}

void GameManager::SaveHighScore()
{

}

GameManager::GameManager()
{
	m_ObjectManager = ObjectManager();
	m_ObjectGenerator = ObjectGenerator();
	m_InputManager = InputManager();
	m_SceneManager = SceneManager();


}