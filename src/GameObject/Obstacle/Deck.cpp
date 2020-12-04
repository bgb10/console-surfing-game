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

void Deck::HitBy(MovableObject* object)
{
	// Actions on collision between Player and Movable are different
	// stop the object on collision
	object->Stop();
}

void Deck::HitBy(Player* player)
{
	// decrease life count
	if (life_count > 0)
		life_count--;

	// stop player on collision, resume playing by pressing down arrow
	player->Stop();

	// make player invincible for 5 in-game unit distances
	player->SetInvincibleDistance(5.0);
}