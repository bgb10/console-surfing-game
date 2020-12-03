#include "Current.h"

//Constructors
Current::Current() : Current(0, 0) {}

Current::Current(float x, float y) : Drawback(x, y)
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("▒");
}

void Current::HitBy(MovableObject& object)
{
	object.SetSpeedByFactor(0.8f);
}

void Current::HitBy(Player& player)
{
	player.SetSpeedByFactor(0.8f);
}