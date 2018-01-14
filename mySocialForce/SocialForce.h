#ifndef SOCIALFORCE_H
#define SOCIALFORCE_H

#include "Point.h"
#include "Line.h"
#include "Wall.h"
#include "Agent.h"
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

//social force engine
//contain wall, agent and all methods to simulation
class SocialForce{
    private:
        //vector wall
        vector<Wall> myWalls;    
        vector<Agent> myAgents;
    
    public:
        //constructor with out parameters
        SocialForce();

        ///
        //Method for walls---------------------
        ///
        //constructor with parameters
        void createWalls();
        //add a wall to vector wall
        void addWall(Wall);
        //get data from wall
        vector<Wall> getWalls();

        ///
        //Method for agents----------------------
        ///
        //create a lot of agent
        void createAgents(int);
        //add agent to database
        void addAgent(Agent);
        //make movement for agents for steptime
        void nextState(float);
        //get data from agemts
        vector<Agent> getAgents();
		static float SocialForce::randomFloat(float lowerBound, float upperBound);
};
#endif