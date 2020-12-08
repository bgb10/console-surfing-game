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
	SetTexture(" |> -==-");
	is_collidable = true;
}

void Buoy::HitBy(MovableObject* object)
{
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
				object->RotateRight();
				object->RotateRight();
			}
			else
			{
				// object was going left
				object->RotateLeft();
				object->RotateLeft();
			}
		}
	}
}

void Buoy::HitBy(Player* player)
{
	if (is_collidable)
	{
		// Actions on collision between Player and Movable are the same
		// call Buoy::HitBy(MovableObject* object)
		Buoy::HitBy(dynamic_cast<MovableObject*>(player));
	}
}