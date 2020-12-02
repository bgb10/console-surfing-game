#include "Boost.h"

extern int boost_count;

//Constructors
Boost::Boost() : Item() {}
Boost::Boost(float x, float y) : Item(x, y){}

void Boost::HitBy(GameObject& object) 
{
	boost_count++;
}