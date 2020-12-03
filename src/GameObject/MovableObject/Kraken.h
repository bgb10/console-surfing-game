#ifndef KRAKEN_H
#define KRAKEN_H

#include "../MovableObject.h"
#include "Player.h"

class Kraken : public MovableObject {

public:
	Kraken(Player& player);
	Kraken(float x, float y, Player& player);

public:
	void HitBy(MovableObject& object);
	void Move(double delta_time);
};

#endif