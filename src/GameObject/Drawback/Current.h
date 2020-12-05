#ifndef CURRENT_H
#define CURRENT_H

#include "../Drawback.h"

class Current : public Drawback {
private:
	bool is_collidable;
public:
	Current();
	Current(float x, float y);

public:
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
};

#endif