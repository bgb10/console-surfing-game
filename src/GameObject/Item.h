#ifndef ITEM_H
#define ITEM_H

#include "../GameObject.h"
#include "MovableObject.h"

class Item : public GameObject {

public:
	Item();
	Item(float x, float y);
	virtual void HitBy(MovableObject& object) = 0;
	virtual void HitBy(Player& player) = 0;
};

#endif