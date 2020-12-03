#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../GameObject.h"
#include "MovableObject.h"

class Obstacle : public GameObject {
	
public:
	Obstacle();
	Obstacle(float x, float y);
	virtual void HitBy(MovableObject& object) = 0;
	virtual void HitBy(Player& player) = 0;
};

#endif