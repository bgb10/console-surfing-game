#include "MovableObject.h"
#include <cmath>

const double PI = 3.14159265;

//Constructors
MovableObject::MovableObject() : GameObject() {}
MovableObject::MovableObject(float x, float y) : GameObject(x, y) {}

void MovableObject::Stop() 
{
	this->velocity_x = 0;
	this->velocity_y = 0;
}

//getters
float MovableObject::GetVelocityX() { return this->velocity_x; }
float MovableObject::GetVelocityY() { return this->velocity_y; }
float  MovableObject::GetSpeed()
{
	return sqrt(pow(this->velocity_x, 2) + pow(this->velocity_y, 2));
}

//setters
void MovableObject::SetVelocityX(float velocity_x) { this->velocity_x = velocity_x; }
void MovableObject::SetVeloctiyY(float velocity_y) { this->velocity_y = velocity_y; }
void MovableObject::SetSpeedByFactor(float factor)
{
	this->velocity_x = this->velocity_x * factor;
	this->velocity_y = this->velocity_y * factor;
}


void MovableObject::SetDirection(int direction) {
	switch (direction) {
	case -2:/*8'o clock dir*/
		this->velocity_x = tan((4 / 3) * PI); break;//240 DEGREE
	case -1:/*7'o clock dir*/
		this->velocity_x = tan((7 / 6) * PI); break;//210 DEGREE
	case 0:/*6'o clock dir*/
		this->velocity_x = tan(PI); break;//180 DEGREE
	case 1:/*5'o clock dir*/
		this->velocity_x = tan((5 / 6) * PI); break;//150 DEGREE
	case 2:/*4'o clock dir*/
		this->velocity_x = tan((2 / 3) * PI); break;//120 DEGREE
	}
}
void MovableObject::RotateRight()
{
	this->velocity_x = tan(atan(this->velocity_x) - (22 * PI / 180));
}
void MovableObject::RotateLeft() 
{
	this->velocity_x = tan(atan(this->velocity_x) + (22 * PI / 180));
}
void MovableObject::ResetRotate() { this->velocity_x = 0; }

