#include "Kraken.h"

//Constructors
Kraken::Kraken() : MovableObject() {}
Kraken::Kraken(float x, float y) : MovableObject(x, y) {}

//gameover?
void Kraken::HitBy(GameObject& object) 
{
	life_count = 0;
}

/*
void Kraken::Move(Player& player){

}
*/