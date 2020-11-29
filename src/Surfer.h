#define SURFER_H

#include "MoveableObject.h"

class Surfer : public MoveableObject {

public:
	Surfer();
	Surfer(float x, float y);

public:
	void HitBy(GameObject& object);
	void Move();
};
