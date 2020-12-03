#include "Drawback.h"

#include "Drawback/Current.h"
#include "Drawback/Seaweed.h"

// Constructors
Drawback::Drawback() : GameObject() {}
Drawback::Drawback(float x, float y) : GameObject(x, y) {}

Drawback* Drawback::Generate(float x, float y)
{
	Drawback* object;

	srand(time(0));

	if (rand() % 100 > 50)
		object = new Current(x, y);
	else
		object = new Seaweed(x, y);

	return object;
}