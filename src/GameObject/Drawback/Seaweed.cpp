#include "Seaweed.h"

// Constructors
Seaweed::Seaweed() : Seaweed(0, 0) {}

Seaweed::Seaweed(float x, float y) : Drawback(x, y)
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("ψ");
	is_collidable = true;
}

void Seaweed::HitBy(MovableObject* object)
{
	if (is_collidable)
	{
		is_collidable = false;
		object->SetSpeedByFactor(0.8f);
	}
}

void Seaweed::HitBy(Player* player)
{
	if (is_collidable)
	{
		is_collidable = false;
		player->SetSpeedByFactor(0.8f);
	}
}