#include "WayPoint.h"
#include <iostream>

using namespace std;

WayPoint::WayPoint(int id, float x, float y, float r) {
	this->id = id;
	this->position = Point(x, y);
	this->radius = r;
}

WayPoint::WayPoint(int id, Point p, float r) {
	this->id = id;
	this->position = p;
	this->radius = r;
}

Vector2 WayPoint::getForce(Point agentPos, bool* isReached) {
	Vector2 vec = Vector2(agentPos, position);
	float length = vec.getLength();

	if (isReached != NULL) {
		if (length < radius)
			*isReached = true;
		else
			*isReached = false;
		
	}

	return vec.normalize();
}