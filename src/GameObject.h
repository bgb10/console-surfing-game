#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject 
{
private:
	static int object_count;
	int object_id;
	float center_x;
	float center_y;
	float width;
	float height;
	std::string texture;

public:
	GameObject();
	GameObject(float x, float y);
	GameObject(float x, float y, float width, float height);

public:
	bool operator == (const GameObject& o);

public:
	int GetID() const;
	float GetCenterX() const;
	float GetCenterY() const;
	float GetWidth() const;
	float GetHeight() const;
	std::string GetTexture() const;

	void SetCenter(float px, float py);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetTexture(std::string texture);
	
	bool HasIntersected(GameObject& object);
	virtual void HitBy(GameObject& object) = 0;
};

#endif