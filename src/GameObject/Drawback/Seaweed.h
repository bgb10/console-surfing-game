#ifndef SEAWEED_H
#define SEAWEED_H

#include "../Drawback.h"

class Seaweed : public Drawback {
private:
	bool is_collidable;
public:
	Seaweed();
	Seaweed(float x, float y);

public:
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
};

#endif