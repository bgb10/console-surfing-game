#include "Player.h"

Player::Player() : Player(0, 0) {}

Player::Player(float x, float y) : MovableObject(x, y)
{
	SetWidth(2);
	SetHeight(2);
	SetDirection(0); // set default texture
	SetPlayer(true);
}

void Player::SetSpeed()
{
	// If Player keep going, speed increases until speed <= 4.5f
	if (this->GetSpeed() <= 4.0f)
	{
		this->SetSpeedByFactor(1.002f);
	}
}

void Player::Move(double delta_time)
{
	MovableObject::Move(delta_time);
}
	
void Player::HitBy(MovableObject* object)
{
	// this will not be called
	// do nothing
}

void Player::HitBy(Player* player)
{
	// this will not be called
	// do nothing
}

void Player::SetDirection(int d) 
{
	switch (d) {
	case 2:/*8'o clock dir*/
		SetTexture("  // // "); break;
	case 1:/*7'o clock dir*/
		SetTexture(" /]  [/ "); break;
	case 0:/*6'o clock dir*/
		SetTexture(" []  [] "); break;
	case -1:/*5'o clock dir*/
		SetTexture(" [\\  \\] "); break;
	case -2:/*4'o clock dir*/
		SetTexture(" \\\\   \\\\"); break;
	}

	MovableObject::SetDirection(d);
}

void Player::RotateRight()
{
	SetDirection(direction + 1);
}
void Player::RotateLeft()
{
	SetDirection(direction - 1);
}
void Player::ResetRotate()
{
	SetDirection(0);
}

void Player::SetInvincibleDistance(float distance)
{
	invincible_distance = distance + this->GetCenterY();
	invincible = true;
}

bool Player::CheckInvincible()
{
	if (invincible)
	{
		if (this->GetCenterY() > invincible_distance)
		{
			invincible = false;
		}
		return invincible;
	}
	return invincible;
}