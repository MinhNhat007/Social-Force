#ifndef AGENT_H
#define AGENT_H

#include "Point.h"

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
        
        //set methods
        void setID();
        void setRadius();
        void setDesiredSpeed();
        void setPosition(Point);
        void setDestination(Point);
};
#endif