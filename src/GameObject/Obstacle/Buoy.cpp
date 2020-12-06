#include "Buoy.h"
#include "../MovableObject/Player.h"

#include <random> // Random

extern int life_count;

// Constructors
Buoy::Buoy() : Buoy(0, 0) {}

Buoy::Buoy(float x, float y) : Obstacle(x, y)
{
	SetWidth(2);
	SetHeight(2);
	SetTexture(" |>~-==-");
	is_collidable = true;
}

void Buoy::HitBy(MovableObject* object)
{
	/*
	if (is_collidable)
	{
		is_collidable = false;

		// Invert the moving direction
		if (object->GetVelocityX() == 0.0)
		{
			srand(GetTickCount());

			if (rand() % 100 > 50)
				object->RotateLeft();
			else
				object->RotateRight();
		}
		else
		{
			if (object->GetVelocityX() > 0)
			{
				// object was going right
				object->RotateLeft();
				object->RotateLeft();
			}
			else
			{
				// object was going left
				object->RotateRight();
				object->RotateRight();
			}
		}
	}
	*/
	if (is_collidable)
	{
		is_collidable = false;

		// Actions on collision between Player and Movable are different
		// stop the object on collision
		//object->Stop();
		object->has_collision = true;
	}
}

void Buoy::HitBy(Player* player)
{
	/*
	if (is_collidable)
	{
		is_collidable = false;

		// Actions on collision between Player and Movable are the same
		// call Buoy::HitBy(MovableObject* object)
		Buoy::HitBy(dynamic_cast<MovableObject*>(player));
	}
	*/
	if (is_collidable)
	{
		is_collidable = false;

		// decrease life count
		if (life_count > 0)
			life_count--;

		// stop player on collision, resume playing by pressing down arrow
		player->Stop();

		// make player invincible for 5 in-game unit distances
		player->SetInvincibleDistance(5.0);
	}
}