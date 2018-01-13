#ifndef WALL_H
#define WALL_H

#include "Point.h"
#include "Vector2.h"

class WayPoint
{
public:
	WayPoint(int id, float x, float y, int radius);
	WayPoint(int id, Point p, int radius);
	~WayPoint() {};

	Vector2 getForce(float posX, float posY, bool* isReached);

protected:
	int id;
	Point position;
	int radius;
};

#endif