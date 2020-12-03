#ifndef DRAWBACK_H
#define DRAWBACK_H

#include "../GameObject.h"
#include "MovableObject.h"

class Drawback : public GameObject {
	
public:
	Drawback();
	Drawback(float x, float y);
	virtual void HitBy(MovableObject& object) = 0;
	virtual void HitBy(Player& player) = 0;
};

#endif