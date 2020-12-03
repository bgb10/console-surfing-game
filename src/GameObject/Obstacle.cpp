#include "Obstacle.h"

#include "Obstacle/Buoy.h"
#include "Obstacle/Deck.h"

// Constructors
Obstacle::Obstacle() : GameObject() {}
Obstacle::Obstacle(float x, float y) : GameObject(x, y) {}

Obstacle* Obstacle::Generate(float x, float y)
{
	Obstacle* object;

	srand(time(0));

	if (rand() % 100 > 50)
		object = new Buoy(x, y);
	else
		object = new Deck(x, y);

	return object;
}