#ifndef BUOY_H
#define BUOY_H

#include "../Obstacle.h"

class Buoy : public Obstacle {
private:
	bool is_collidable = true;
	
public:
	Buoy();
	Buoy(float x, float y);

public:
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
};

#endif