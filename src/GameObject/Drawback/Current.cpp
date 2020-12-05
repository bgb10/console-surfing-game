#include "Current.h"

//Constructors
Current::Current() : Current(0, 0) {}

Current::Current(float x, float y) : Drawback(x, y)
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("▒");
	is_collidable = true;
}

void Current::HitBy(MovableObject* object)
{
	if (is_collidable)
	{
		is_collidable = false;
		//object->SetSpeedByFactor(0.7f);
		object->has_collision = true;
	}
}

void Current::HitBy(Player* player)
{
	if (is_collidable)
	{
		is_collidable = false;
		player->SetSpeedByFactor(0.7f);
	}
}