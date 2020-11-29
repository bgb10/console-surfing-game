#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject {
private:
	int object_count;
	int object_id;
	int center_x;
	int center_y;
	float width;
	float height;
	std::string texture;

public:
	GameObject();
	GameObject(float x, float y);
	GameObject(float x, float y, float width, float height);

public:
	bool operator== (const GameObject& o);

public:
	int GetID();
	float GetCenterX();
	float GetCenterY();
	float GetWidth();
	float GetHeight();
	std::string GetTexture();
	void SetCenter(float px, float py);
	void SetWidth(float width);
	void SetHeight(float height);
	void SetTexture(std::string texture);
	bool HasIntersected(GameObject& object);
	void HitBy(GameObject& object);
};

#endif