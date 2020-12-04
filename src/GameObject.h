#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <windows.h>

// #include "GameObject/MovableObject.h"
// #include "GameObject/MovableObject/Player.h"

class MovableObject;
class Player;

class GameObject 
{
private:
	static int object_count;
	int object_id;
	float center_x;
	float center_y;
	int width;
	int height;
	std::string texture;
protected:
	bool is_visible = true;

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
	int GetWidth() const;
	int GetHeight() const;
	bool IsVisible();
	std::string GetTexture() const;

	void SetCenter(float px, float py);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetTexture(std::string texture);
	void SetVisible(bool is_visible);
	
	bool HasIntersected(GameObject& object);
	virtual void HitBy(MovableObject* object) = 0;
	virtual void HitBy(Player* player) = 0;
};

#endif