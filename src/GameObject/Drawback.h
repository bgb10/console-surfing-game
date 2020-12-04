#ifndef DRAWBACK_H
#define DRAWBACK_H

#include "../GameObject.h"
#include "MovableObject.h"
#include "MovableObject/Player.h"

#include <random> // Random
#include <ctime>

class Drawback : public GameObject {
	
public:
	Drawback();
	Drawback(float x, float y);
	virtual void HitBy(MovableObject* object) = 0;
	virtual void HitBy(Player* player) = 0;
	static Drawback* Generate(float x, float y);
};

#endif