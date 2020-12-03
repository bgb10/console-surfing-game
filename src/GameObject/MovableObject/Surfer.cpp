#include "Surfer.h"

Surfer::Surfer() : Surfer(0, 0)
{

}

Surfer::Surfer(float x, float y) : MovableObject(x, y)
{

}

void Surfer::HitBy(MovableObject& object)
{

}

void Surfer::Move(double delta_time)
{
	MovableObject::Move(delta_time);
}