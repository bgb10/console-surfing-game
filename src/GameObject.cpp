#include "GameObject.h"

//static member variable init
int GameObject::object_count = 0;

bool GameObject::operator == (const GameObject& o) 
{
	return (this->GetID() == o.GetID()) ? true : false;
}


bool GameObject::HasIntersected(GameObject& object) 
{
	// collision detected!
	if (object.GetPlayer())
	{
		float dx = this->GetCenterX() - object.GetCenterX();
		float dy = this->GetCenterY() - object.GetCenterY();
		int dw = this->GetWidth();
		int dh = this->GetHeight() + 1;
		if (dx < 0) dx *= -1;
		if (dy < 0) dy *= -1;
		if (dx < dw && dy < dh) return true;
		else return false;
	}
	else
	{
		float dx = this->GetCenterX() - object.GetCenterX();
		float dy = this->GetCenterY() - object.GetCenterY();
		int dw = this->GetWidth() + object.GetWidth();
		int dh = this->GetHeight() + object.GetHeight();
		if (dx < 0) dx *= -1;
		if (dy < 0) dy *= -1;
		if (dx < dw && dy < dh) return true;
		else return false;
	}
}

/*Getters*/
int GameObject::GetID() const { return this->object_id; }
float GameObject::GetCenterX() const { return this->center_x; }
float GameObject::GetCenterY() const { return this->center_y; }
int GameObject::GetWidth() const { return this->width; }
int GameObject::GetHeight() const { return this->height; }
bool GameObject::IsVisible() { return this->is_visible; }
std::string GameObject::GetTexture() const { return this->texture; }
bool GameObject::GetPlayer() { return this->isplayer; }

/*Setters*/
void GameObject::SetCenter(float px, float py) { this->center_x = px; this->center_y = py; }
void GameObject::SetWidth(int width) { this->width = width; }
void GameObject::SetHeight(int height) { this->height = height; }
void GameObject::SetTexture(std::string texture) { this->texture = texture; }
void GameObject::SetVisible(bool is_visible) { this->is_visible = is_visible; }
void GameObject::SetPlayer(bool is_player) { this->isplayer = is_player; }

GameObject::GameObject() 
{
	this->object_count += 1;
	this->object_id = this->object_count;
	this->center_x = 0.0f;
	this->center_y = 0.0f;
	this->height = 0.0f;
	this->width = 0.0f;
}

GameObject::GameObject(float x, float y) 
{
	this->object_count += 1;
	this->object_id = this->object_count;
	this->center_x = x;
	this->center_y = y;
	this->height = 0.0f;
	this->width = 0.0f;
}

GameObject::GameObject(float x, float y, float width, float height) 
{
	this->object_count += 1;
	this->object_id = this->object_count;
	this->center_x = x;
	this->center_y = y;
	this->height = width;
	this->width = height;
}