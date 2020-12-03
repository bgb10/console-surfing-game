#include "Surfer.h"

#include <windows.h>

extern int life_count;

Surfer::Surfer() : Surfer(0, 0) {}

Surfer::Surfer(float x, float y) : MovableObject(x, y)
{
	SetWidth(1);
	SetHeight(2);
	SetTexture("¡û¡ú");
}

void Surfer::HitBy(MovableObject& object)
{
	// called only when Surfer collides with Kraken
	// Surfer will stop on collision, this is handled in Kraken::HitBy(MovableObject& object)
	// do nothing
}

void Surfer::HitBy(Player& player)
{
	// decrease life count
	if (life_count > 0)
		life_count--;

	// stop player on collision, resume playing by pressing down arrow
	player.Stop();

	// make player invincible for 5 in-game unit distances
	player.SetInvincibleDistance(5.0);
}

void Surfer::Move(double delta_time)
{
	srand(GetTickCount());
	int random = rand() % 100;

	if (random < 20)
		RotateLeft();
	else if (random > 80)
		RotateRight();
	else
		ResetRotate();

	MovableObject::Move(delta_time);
}