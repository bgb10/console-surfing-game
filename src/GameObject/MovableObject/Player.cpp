#include "Player.h"

Player::Player() : Player(0, 0)
{

}

Player::Player(float x, float y) : MovableObject(x, y)
{

}

void Player::Move(double delta_time)
{
	MovableObject::Move(delta_time);
}

bool Player::HasIntersected(GameObject& object)
{

}
	
void Player::HitBy(MovableObject& object)
{

}

void Player::SetInvincibleDistance(float distance)
{

}