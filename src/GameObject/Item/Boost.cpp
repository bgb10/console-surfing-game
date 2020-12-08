#include "Boost.h"

extern int boost_count;

// Constructors
Boost::Boost() : Boost(0, 0) {}

Boost::Boost(float x, float y) : Item(x, y) 
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("ⓑ");
	is_collidable = true;
}

void Boost::HitBy(MovableObject* object)
{
	// do nothing if other entities hit boost item
}

void Boost::HitBy(Player* player)
{
	// increase boost count
	// maximum boost count is 3
	if (is_collidable)
	{
		is_collidable = false;
		SetTexture("  "); // hide item
		SetCenter(0, -100.0f);
		if (boost_count < 3) boost_count++;
	}
}