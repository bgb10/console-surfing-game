#include "Kraken.h"

extern int life_count;

//Constructors
Kraken::Kraken(Player* player) : Kraken(0, 0, player) { }

Kraken::Kraken(float x, float y, Player* player) : MovableObject(x, y) 
{
	this->player = player;
	SetWidth(5);
	SetHeight(3);
	SetTexture(" _ \\__/ _  /\\(--)/\\ ~oO0oO0Oo~");
	SetVelocityY(1.0f);
}

void Kraken::HitBy(MovableObject* object)
{
	// stop object on collision
	object->Stop();

	has_collision = true;
}

void Kraken::HitBy(Player* player)
{
	// Gameover
	life_count = 0;

	// stop player on collision, stop playing
	player->Stop();
}

void Kraken::Move(double delta_time)
{
	if (has_collision) return;

	// kraken follows the player
	this->SetVelocityX(player->GetCenterX() - this->GetCenterX());
	this->SetVelocityY(player->GetCenterY() - this->GetCenterY());

	// adjust speed relative to user speed
	if (player->GetSpeed() > 0.5f)
	{
		this->SetSpeedByFactor((player->GetSpeed() * 1.00001) / this->GetSpeed());
	}
	else
	{
		this->SetSpeedByFactor(1.0f / this->GetSpeed());
	}

	MovableObject::Move(delta_time);
}