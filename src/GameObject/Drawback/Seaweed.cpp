#include "Seaweed.h"

// Constructors
Seaweed::Seaweed() : Seaweed(0, 0) {}

Seaweed::Seaweed(float x, float y) : Drawback(x, y)
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("ψ");
}

void Seaweed::HitBy(MovableObject* object)
{
	object->SetSpeedByFactor(0.6f);
}

void Seaweed::HitBy(Player* player)
{
	player->SetSpeedByFactor(0.6f);
}