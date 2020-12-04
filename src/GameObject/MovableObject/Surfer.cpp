#include "Surfer.h"

#include <windows.h>

extern int life_count;

Surfer::Surfer() : Surfer(0, 0) {}

Surfer::Surfer(float x, float y) : MovableObject(x, y)
{
	SetWidth(1);
	SetHeight(2);
	SetTexture("/\\\\/");
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

	// makes invincible
	this->is_visible = false;

	// stop player on collision, resume playing by pressing down arrow
	player.Stop();

	// make player invincible for 5 in-game unit distances
	player.SetInvincibleDistance(5.0);
}

void Surfer::Move(double delta_time)
{
	srand(GetTickCount());
	int random = rand() % 100;

	// 20% chance to rotate left
	// 20% chance to rotate right
	// 20% chance to reset rotate
	// 40% chance to stay as where it goes
	if (random < 20)
		RotateLeft();
	else if (60 < random && random < 80)
		RotateRight();
	else if (80 < random)
		ResetRotate();

	random = rand() % 100;

	// 20% chance to stop
	// 20% chance to accelerate
	// 20% chance to decelerate
	// 40% chance to stay as it goes
	if (random < 20)
		Stop();
	else if (60 < random && random < 80)
		SetVelocityY(GetVelocityY() + 0.5f);
	else if (80 < random)
	{
		if (GetVelocityY() < 0.2f)
			Stop();
		else
			SetVelocityY(GetVelocityY() - 0.2f);
	}

	MovableObject::Move(delta_time);
}