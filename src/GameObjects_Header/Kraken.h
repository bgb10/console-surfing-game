#ifndef KRAKEN_H
#define KRAKEN_H

#include "MoveableObject.h"

class Kraken : public MoveableObject {

public:
	Kraken();
	Kraken(float x, float y);

public:
	void HitBy(GameObject& object);
	void Move();
};

#endif