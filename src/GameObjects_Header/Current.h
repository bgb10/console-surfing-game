#ifndef CURRENT_H
#define CURRENT_H

#include "Drawback.h"

class Current : public Drawback {

public:
	Current();
	Current(float x, float y);

public:
	void HitBy(GameObject& object);
};
#endif