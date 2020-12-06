#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "../GameObject.h"

# define PI 3.14159265

class MovableObject : public GameObject {

protected:
	short direction = 0;
	float ratio = 5;

private:
	float velocity_x = 0;
	float velocity_y = 0;

public:
	bool has_collision = false;
	MovableObject();
	MovableObject(float x, float y);
	virtual void HitBy(MovableObject* object) = 0;
	virtual void HitBy(Player* player) = 0;

public:
	virtual void Move(double delta_time);
	float GetVelocityX();
	float GetVelocityY();
	float GetSpeed();
	void SetVelocityX(float velocity_x);
	void SetVelocityY(float velocity_y);
	virtual void SetDirection(int direction);
	virtual void RotateRight();
	virtual void RotateLeft();
	virtual void ResetRotate();
	void SetSpeedByFactor(float factor);
	void Stop();
	bool HasIntersected_(MovableObject* object);
};

#endif
