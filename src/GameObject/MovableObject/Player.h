#ifndef PLAYER_H
#define PLAYER_H

#include "../MovableObject.h"

class Player : public MovableObject {
	
private:
	float invincible_start_x;
	float invincible_start_y;
	float invincible_distance;

public:
	Player();
	Player(float x, float y);

public:
	void Move(double delta_time);
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
	void SetInvincibleDistance(float distance);
	void SetDirection(int direction);
	void RotateRight();
	void RotateLeft();
	void ResetRotate();
};

#endif
