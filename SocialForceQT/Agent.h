#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <random>
#include <iostream>
#include <deque>
#include "Point.h"
#include "Wall.h"
#include "Vector2.h"
#include "WayPoint.h"
using namespace std;

/**
 * @brief The Agent class involved with every processes of agent
 */
class Agent{
    /**
     * @brief currentID numer of agents objects
     */
    static int currentID;

  private:
    int id;               //id
    float radius;         //r
    float desiredSpeed;   //v_o
    float relaxationTime; //t: relaxation time
    Point position;//location at considering time
    WayPoint* destination;    //destination which the agent would like to go
    Vector2 currentSpeed; //current v
	deque<WayPoint*> wayPoints; //deque with waypoints
    float actualForce;  // this is length of agentsForce + obstacleForce

  public:
    /**
     * constructor without parameters, without choosing destination point
     */
    Agent(Point);

    /**
     * @brief addWayPoint adds next agent's waypoint
     * automatically adds destination point as first in deque
     */
	void addWayPoint(WayPoint*);

    /**
     * @brief getWayPoints function gets double-bind list with waypoints
     * @return deque with WayPoint* objects
     */
	deque<WayPoint*> getWayPoints() { return wayPoints; }

    /**
     * @brief makeAMove function indicates the move after stepTime
     * @param walls vector of walls in scene
     * @param agents vector of all agents
     * @param stepTime stepTime to move
     * @param destForceCoe destination force coefficient
     * @param obstacleForceCoe obstacle force coefficient
     * @param agentsForceCoe other agents force coefficient
     */
    void makeAMove(vector<Wall> walls, vector<Agent> agents, float stepTime,
                   float destForceCoe,float obstacleForceCoe,float agentsForceCoe);

    /**
     * @brief wallInteractForce calculates Social Force
     * @param walls vector of walls in scene
     * @return social force vector
     */
    Vector2 wallInteractForce(vector<Wall> walls);

    /**
     * @brief internalForce calcualates interal force
     * @return internal force vector
     */
    Vector2 internalForce();

    /**
     * @brief agentInteractForce calculates interaction force between agents
     * @param agents vector of all agents in scene
     * @return interact force vector
     */
    Vector2 agentInteractForce(vector<Agent> agents);

    /**
     * @brief getNearestPointFromWalls finds the point at wall which is the nearest with the agent
     * @param walls vector of walls in scene
     * @return the nearest point form walls
     */
    Point getNearestPointFromWalls(vector<Wall> walls);

    /**
     * @brief computeDesiredVector finds Vector for disiredVector
     * additionally manages agent's waypoints
     * if reached, change waypoints to next one
     * @return desired force vector
     */
    Vector2 computeDesiredVector();

    /**
     * @brief isReachDestination checks if agent reached destination
     * @return true if reached
     */
    bool isReachDestination();

    /**
     * @brief setID sets agent id
     * @param id agent id
     */
    void setID(int id);

    /**
     * @brief setRadius sets agent radius
     */
    void setRadius();

    /**
     * @brief setDesiredSpeed generate agent's desired speed
     */
    void setDesiredSpeed();

    /**
     * @brief setPosition sets new agent's position
     * @param p position point to be set
     */
    void setPosition(Point p);

    /**
     * @brief setRelaxationTime generates relaxation time
     */
    void setRelaxationTime();

    /**
     * @brief getPosition gets actual position
     * @return agent's actual position
     */
    Point getPosition();

    /**
     * @brief getDestination gets actual destination waypoint
     * @return actual destination waypoint
     * if NULL, agents reach final destination
     */
    WayPoint* getDestination();

    /**
     * @brief getID gets agent's ID
     * @return ID
     */
    int getID();

    /**
     * @brief getRadius gets agent's radius
     * @return agent's radius
     */
    float getRadius() const;

    /**
     * @brief getCurrentSpeed gets current speed vector
     * @return current speed vector
     */
    Vector2 getCurrentSpeed() const;

    /**
     * @brief getActualForce gets actual force as length of (ObstacleForce and interactForce)
     * @return value of force
     */
    float getActualForce() const;
};
#endif
