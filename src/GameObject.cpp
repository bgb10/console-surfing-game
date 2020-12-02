#include "GameObject.h"

//static member variable init
int GameObject::object_count = 0;

bool GameObject::operator == (const GameObject& o) 
{
	return (this->GetID() == o.GetID()) ? true : false;
}


bool GameObject::HasIntersected(GameObject& object) 
{
	//x, y,가로, 세로를 편하게 찾기 위해 열거형 선언
	enum object_num {x, y, width, height};
	//함수 호출을 한번만 선언하게 해서 속도 향상	
	float object_data[4] = { 
		object.GetCenterX(), object.GetCenterY(), 
		object.GetWidth(), object.GetHeight() 
	};

	// collision detected!
	return 
		(
			(this->center_x < object_data[x] + object_data[width]) && 
			(this->center_x + this->width > object_data[x]) &&
			(this->center_y < object_data[y] + object_data[height]) && 
			(this->center_y + this->height > object_data[y])
		) 
		? true : false;
			
}


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