#ifndef DECK_H
#define DECK_H

#include "Obstacle.h"

class Deck : public Obstacle {
	
public:
	Deck();
	Deck(float x, float y);

public:
	void HitBy(MovableObject& object);
};

#endif