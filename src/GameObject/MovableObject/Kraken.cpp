#include "Kraken.h"

extern int life_count;

Player& m_player;

//Constructors
Kraken::Kraken(Player& player) : Kraken(0, 0, player) { }

Kraken::Kraken(float x, float y, Player& player) : MovableObject(x, y) 
{
	m_player = player;
}

void Kraken::HitBy(MovableObject& object)
{
	// Gameover
	life_count = 0;
}

void Kraken::Move(double delta_time)
{
	// kraken follows the player
	if (m_player.GetCenterX() < this->GetCenterX())
		this->RotateLeft(); // player is on the left of player, rotate left
	else
		this->RotateRight(); // player is on the right of player, rotate right

	MovableObject::Move(delta_time);
}