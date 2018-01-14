#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "Point.h"
#include "Vector2.h"
#include "Point.h"

class WayPoint
{
public:
	WayPoint(int id, float x, float y, float radius);
	WayPoint(int id, Point p, float radius);
	~WayPoint() {};
	int getId() { return id; }

	Vector2 getForce(Point agentPos, bool* isReached);

protected:
	int id;
	Point position;
	float radius;
};

#endif