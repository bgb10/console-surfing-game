#ifndef ITEM_H
#define ITEM_H

#include "../GameObject.h"
#include "MovableObject.h"

#include <random> // Random
#include <ctime>

class Item : public GameObject {

public:
	Item();
	Item(float x, float y);
	virtual void HitBy(MovableObject& object) = 0;
	virtual void HitBy(Player& player) = 0;
	static Item* Generate(float x, float y);
};

#endif