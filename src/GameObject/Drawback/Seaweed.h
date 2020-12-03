#ifndef SEAWEED_H
#define SEAWEED_H

#include "../Drawback.h"

class Seaweed : public Drawback {

public:
	Seaweed();
	Seaweed(float x, float y);

public:
	void HitBy(MovableObject& object);
};

#endif