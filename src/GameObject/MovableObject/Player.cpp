#include "Player.h"

Player::Player() : Player(0, 0) {}

Player::Player(float x, float y) : MovableObject(x, y)
{
	SetWidth(1);
	SetHeight(1);
	SetTexture("[]"); // TODO: change texture
}

void Player::Move(double delta_time)
{
	MovableObject::Move(delta_time);
}
	
void Player::HitBy(MovableObject& object)
{
	// this will not be called
	// do nothing
}

void Player::HitBy(Player& player)
{
	// this will not be called
	// do nothing
}

void Player::SetInvincibleDistance(float distance)
{

}