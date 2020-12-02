#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "../GameObject.h"

class MovableObject : public GameObject{

private:
	float velocity_x;
	float velocity_y;

public:
	MovableObject();
	MovableObject(float x, float y);

public:
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
