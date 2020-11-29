#ifndef MOVEABLEOBJECT_H
#define MOVEABLEOBJECT_H

#include "GameObject.h"

class MoveableObject : public GameObject{

private:
	float velocity_x;
	float velocity_y;

public:
	MoveableObject();
	MoveableObject(float x, float y);

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
