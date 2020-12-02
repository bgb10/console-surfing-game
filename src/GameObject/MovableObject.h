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
	void SetVelocityX();
	void SetVeloctiyY();
	void SetDirection(int direction);
	void SetSpeedByFactor(float factor);
	void Stop();
};

#endif
