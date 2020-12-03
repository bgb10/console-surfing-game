#include "Buoy.h"

bool GameObject::operator == (const GameObject& o) 
{
	return (this->GetID() == o.GetID()) ? true : false;
}

/* soon ... 
bool HasIntersected(GameObject& object);
void HitBy(MovableObject& object);
*/

/*Getters*/
int GameObject::GetID() const { return this->object_id; }
float GameObject::GetCenterX() const { return this->center_x; }
float GameObject::GetCenterY() const { return this->center_y; }
float GameObject::GetWidth() const { return this->width; }
float GameObject::GetHeight() const { return this->height; }
std::string GameObject::GetTexture() const { return this->texture; }

/*Setters*/
void GameObject::SetCenter(float px, float py) { this->center_x = px; this->center_y = py; }
void GameObject::SetWidth(float width) { this->width = width; }
void GameObject::SetHeight(float height) { this->height = height; }
void GameObject::SetTexture(std::string texture) { this->texture = texture; }

GameObject::GameObject() 
{
	this->object_count = 0;
	this->object_id = 0;
	this->center_x = 0.0f;
	this->center_y = 0.0f;
	this->height = 0.0f;
	this->width = 0.0f;
}

GameObject::GameObject(float x, float y) 
{
	this->object_count = 0;
	this->object_id = 0;
	this->center_x = x;
	this->center_y = y;
	this->height = 0.0f;
	this->width = 0.0f;
}

GameObject::GameObject(float x, float y, float width, float height) 
{
	this->object_count = 0;
	this->object_id = 0;
	this->center_x = x;
	this->center_y = y;
	this->height = width;
	this->width = height;
}