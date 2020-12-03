#include "Health.h"

extern int life_count;

// Constructors
Health::Health() : Health(0, 0) {}

Health::Health(float x, float y) : Item(x, y) 
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("♥");
}

void Health::HitBy(MovableObject& object)
{
	// do nothing if other entities hit boost item
}

void Health::HitBy(Player& player)
{
	// increase life count
	// maximum life count is 3
	if (life_count < 3)
		life_count++;
}