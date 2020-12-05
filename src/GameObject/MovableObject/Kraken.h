#ifndef KRAKEN_H
#define KRAKEN_H

#include "../MovableObject.h"
#include "Player.h"

class Kraken : public MovableObject {

private:
	Player* player;
	bool has_collision = false;

public:
	// Constructor
	Kraken(Player* player);
	Kraken(float x, float y, Player* player);

	// Member functions
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
	void Move(double delta_time);
};

#endif