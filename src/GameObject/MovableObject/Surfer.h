#ifndef SURFER_H
#define SURFER_H

#include "../MovableObject.h"

class Surfer : public MovableObject {

public:
	Surfer();
	Surfer(float x, float y);

public:
	void HitBy(MovableObject& object);
	void Move(double delta_time);
};

#endif