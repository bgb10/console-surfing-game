#ifndef ITEM_H
#define ITEM_H

#include "../GameObject.h"
#include "MovableObject.h"

class Item : public GameObject {

public:
	Item();
	Item(float x, float y);
};

#endif