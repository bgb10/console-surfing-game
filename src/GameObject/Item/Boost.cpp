#include "Boost.h"

extern int boost_count;

// Constructors
Boost::Boost() : Boost(0, 0) {}

Boost::Boost(float x, float y) : Item(x, y) 
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("ⓔ");
}

void Boost::HitBy(MovableObject& object)
{
	// do nothing if other entities hit boost item
}

void Boost::HitBy(Player& player)
{
	// increase boost count
	// maximum boost count is 3
	if (boost_count < 3)
	{
		boost_count++;
		SetTexture("  "); // hide item
	}
}