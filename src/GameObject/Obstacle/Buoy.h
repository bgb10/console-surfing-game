#ifndef BUOY_H
#define BUOY_H

#include "Obstacle.h"

class Buoy : public Obstacle {
	
public:
	Buoy();
	Buoy(float x, float y);

public:
	void HitBy(GameObject& object);
};

#endif