#ifndef HEALTH_H
#define HEALTH_H

#include "Item.h"

class Health : public Item {

public:
	Health();
	Health(float x, float y);

public:
	void HitBy(GameObject& object);
};

#endif