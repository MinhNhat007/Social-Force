#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <random>
#include <iostream>
#include "Point.h"
#include "Wall.h"
#include "vectorMath.h"
using namespace std;

class Agent{
    static int currentID; //current ID
    private:
        int id; //id
        float radius; //r
        float desiredSpeed; //v_o
        float currentSpeed; //current v
        Point posistion; //location at considering time
        Point destination; //destination which the agent would like to go
    
    public: 
        //constructor without parameters
        Agent(Point, Point);

        //function indicates the move after stepTime
        void makeAMove(vector<Wall>, vector<Agent>, float);
        
        //calculate Social Force
        vectorMath wallInteractForce(vector<Wall>);
        //find the point which is the nearest with the agent
        Point getNearestPointFromWalls(vector<Wall>);

            //set methods
            void setID();
        void setRadius();
        void setDesiredSpeed();
        void setPosition(Point);
        void setDestination(Point);
};
#endif