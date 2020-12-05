#ifndef BOOST_H
#define BOOST_H

#include "../Item.h"

class Boost : public Item {
private:
	bool is_collidable = true;

public:
	Boost();
	Boost(float x, float y);

public:
	void HitBy(MovableObject* object);
	void HitBy(Player* player);
};

#endif