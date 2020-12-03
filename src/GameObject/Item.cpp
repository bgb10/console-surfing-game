#include "Item.h"

#include "Item/Health.h"
#include "Item/Boost.h"

// Constructors
Item::Item() : GameObject() {}
Item::Item(float x, float y) : GameObject(x, y) {}

Item* Item::Generate(float x, float y)
{
	Item* object;

	srand(time(0));

	if (rand() % 100 > 50)
		object = new Health(x, y);
	else
		object = new Boost(x, y);

	return object;
}
