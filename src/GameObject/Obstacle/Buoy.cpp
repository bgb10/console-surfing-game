#include "Buoy.h"

// Constructors
Buoy::Buoy() : Buoy(0, 0) {}

Buoy::Buoy(float x, float y) : Obstacle(x, y)
{
	SetWidth(2);
	SetHeight(2);
	SetTexture(" ▶ ≡≡");
}

void Buoy::HitBy(MovableObject& object)
{
	// Invert the moving direction
	object.SetVelocityX(-object.GetVelocityX());
}