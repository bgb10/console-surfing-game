#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "../GameObject.h"

class MovableObject : public GameObject {

private:
	float velocity_x = 0;
	float velocity_y = 0;

public:
	MovableObject();
	MovableObject(float x, float y);
	virtual void HitBy(MovableObject& object) = 0;
	virtual void HitBy(Player& player) = 0;

public:
	void Move(double delta_time);
	float GetVelocityX();
	float GetVelocityY();
	float GetSpeed();
	void SetVelocityX(float velocity_x);
	void SetVeloctiyY(float velocity_y);
	void SetDirection(int direction);
	void RotateRight();
	void RotateLeft();
	void ResetRotate();
	void SetSpeedByFactor(float factor);
	void Stop();
};

#endif
