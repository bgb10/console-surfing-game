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
	SetVelocityY(player->GetVelocityY() * 1.25);
}

void Kraken::HitBy(MovableObject* object)
{
	// stop object on collision
	object->Stop();
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
	// kraken follows the player
	this->SetVelocityX(player->GetCenterX() - this->GetCenterX());
	this->SetVelocityY(player->GetCenterY() - this->GetCenterY());

	// adjust speed relative to user speed
	this->SetSpeedByFactor((player->GetSpeed() * 1.00001) / this->GetSpeed());

	MovableObject::Move(delta_time);
}