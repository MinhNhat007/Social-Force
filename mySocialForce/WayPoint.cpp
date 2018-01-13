#include "WayPoint.h"

WayPoint::WayPoint(int id, float x, float y, int r) {
	this->id = id;
	this->position = Point(x, y);
	this->radius = r;
}

WayPoint::WayPoint(int id, Point p, int r) {
	this->id = id;
	this->position = p;
	this->radius = r;
}

Vector2 WayPoint::getForce(float posX, float posY, bool* isReached) {
	Vector2 vec = Vector2(position, Point(posX, posY));
	float length = vec.getLength();

	if (isReached != NULL) {
		if (length < radius)
			*isReached = true;
		else
			*isReached = false;
	}

	return vec.normalize();
}