#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "Point.h"
#include "Vector2.h"
#include "Point.h"

/**
 * @brief The WayPoint class representing single way point at scene
 */
class WayPoint
{
public:
    /**
     * @brief WayPoint constructs new way point
     * @param id way point id
     * @param x waypoint x coordinate
     * @param y waypoint y coordinate
     * @param radius waypoint radius
     */
	WayPoint(int id, float x, float y, float radius);

    /**
     * @brief WayPoint constructs new way point
     * @param id way point id
     * @param p point
     * @param radius waypoint radius
     */
	WayPoint(int id, Point p, float radius);

    /**
     * @brief getId gets way point id
     * @return waypoint id
     */
	int getId() { return id; }

    /**
     * @brief getForce gets force from agent to this waypoint
     * if waypoint is reached isReached parameter is set to true
     * @param agentPos agent position
     * @param isReached additional returning value, if set to true, waypoint is reached be agent
     * @return force vector
     */
	Vector2 getForce(Point agentPos, bool* isReached);

    /**
     * @brief getPosition receives waypoint position
     * @return waypoint position
     */
    Point getPosition() const;

    /**
     * @brief setPosition sets waypoint position
     * @param value new position
     */
    void setPosition(const Point &value);

    /**
     * @brief getRadius gets waypoint radius
     * @return waypoint radius
     */
    float getRadius() const;

    /**
     * @brief setRadius sets waypoint radius
     * @param value radius to be set
     */
    void setRadius(float value);

protected:
    int id;
    Point position;
    float radius;
};

#endif
