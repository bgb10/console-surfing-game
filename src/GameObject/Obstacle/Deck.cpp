#include "Deck.h"

extern int life_count;

// Constructors
Deck::Deck() : Deck(0, 0) {}

Deck::Deck(float x, float y) : Obstacle(x, y)
{
	SetWidth(2);
	SetHeight(2);
	SetTexture("▨▨|  |");
}

void Deck::HitBy(MovableObject& object)
{
	if (life_count > 0)
		life_count--;
}