#ifndef PLAYER_H
#define PLAYER_H

#include "MoveableObject.h"

class Player : public MoveableObject{
	
private:
	float invincible_start_x;
	float invincible_start_y;
	float invincible_distance;

public:
	Player();
	Player(float x, float y);

public:
	void Move();
	bool HasIntersected(GameObject& object);
	void HitBy(GameObject& object);
	void SetInvincibleDistance(float distance);
};

#endif
