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

//class agent involved with every processes of agent 
class Agent{
    static int currentID; //current ID
    //attribute from
    /*static float A = 4.5;
    static float n_prim = 3.0;
    static float n = 2.0;
    static float gamma = 0.35;
    static float lambda = 2.0;
    static int a = 3;
    static float b = 0.1;*/

  private:
    int id;               //id
    float radius;         //r
    float desiredSpeed;   //v_o
    float relaxationTime; //t: relaxation time
    Point position;      //location at considering time
    WayPoint* destination;    //destination which the agent would like to go
    Vector2 currentSpeed; //current v
	deque<WayPoint*> wayPoints; //deque with waypoints

  public:
    //constructor without parameters; without choosing destination point
    Agent(Point);

	//automatically adds destination point as first in deque
	void addWayPoint(WayPoint*);
	deque<WayPoint*> getWayPoints() { return wayPoints; }

    //function indicates the move after stepTime
    void makeAMove(vector<Wall>, vector<Agent>, float);

    //calculate Social Force
    Vector2 wallInteractForce(vector<Wall>);
    //calcualte interal force
    Vector2 internalForce();
    //calculate interaction force between agents
    Vector2 agentInteractForce(vector<Agent>);

    //find the point which is the nearest with the agent
    Point getNearestPointFromWalls(vector<Wall>);

    //find Vector for disiredVector
	//additionally manages agent's waypoints
	//if reached, change waypoints
    Vector2 computeDesiredVector();

    //check agent reach destination
    bool isReachDestination();

    //set and get methods
    void setID(int);
    void setRadius();
    void setDesiredSpeed();
    void setPosition(Point);
    void setRelaxationTime();
    Point getPosition();
    WayPoint* getDestination();
    int getID();
};
#endif