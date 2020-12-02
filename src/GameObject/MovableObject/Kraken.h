#ifndef KRAKEN_H
#define KRAKEN_H

#include "../MovableObject.h"
#include "Player.h"

class Kraken : public MovableObject {

public:
	Kraken();
	Kraken(float x, float y);

public:
	void HitBy(GameObject& object);
	void Move(Player& player);
};

#endif