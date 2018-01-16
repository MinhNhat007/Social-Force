#ifndef SOCIALFORCE_H
#define SOCIALFORCE_H

#include "Point.h"
#include "Line.h"
#include "Wall.h"
#include "Agent.h"
#include <vector>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

/**
 * @brief The SocialForce class social force engine
 * contains wall, agent and all methods to simulation
 */
class SocialForce{
    private:
        //vector wall
        vector<Wall> myWalls;    
        vector<Agent> myAgents;
        map<int,WayPoint*> allWayPoints;

        float destForceCoe=1.0;
        float agentsForceCoe=1.0;
        float obstacleForceCoe=1.0;
        string sourceFile;
    public:
        /**
         * @brief SocialForce constructor without parameters
         */
        SocialForce();

        // methodes for walls---------------------------------------
        /**
         * @brief addWall adds wall to scene
         * @param w wall to be added
         */
        void addWall(Wall w);

        /**
         * @brief getWalls gets walls at scene
         * @return walls
         */
        vector<Wall> getWalls();


        //Method for agents----------------------
        /**
         * @brief createAgents create a lot of agent
         * @param n number of agents to be create
         */
        void createAgents(int n);

        /**
         * @brief addAgent adds agent to database
         * @param agent agent to be added
         */
        void addAgent(Agent agent);

        /**
         * @brief nextState makes movement for agents for steptime
         */
        void nextState(float);

        /**
         * @brief getAgents get vector with all agents
         * @return vector with all agents
         */
        vector<Agent> getAgents();

        /**
         * @brief randomFloat static function to generate floate in specific range
         * @param lowerBound lower bound of range
         * @param upperBound upper bound of range
         * @return generated float number
         */
        static float randomFloat(float lowerBound, float upperBound);

        /**
         * @brief getDestForceCoe gets destination force coefficient
         * @return destination force coefficient
         */
        float getDestForceCoe() const;

        /**
         * @brief setDestForceCoe sets destination force coefficient
         * @param value coefficient to be set
         */
        void setDestForceCoe(float value);

        /**
         * @brief getAgentsForceCoe gets other agents interact force coefficient
         * @return other agents' interact force coefficient
         */
        float getAgentsForceCoe() const;

        /**
         * @brief setAgentsForceCoe sets other agents interact force coefficient
         * @param value coefficient to be set
         */
        void setAgentsForceCoe(float value);

        /**
         * @brief getObstacleForceCoe gets obstacles(walls) force coefficient
         * @return coefficient
         */
        float getObstacleForceCoe() const;

        /**
         * @brief setObstacleForceCoe sets obstacle(walls) force coefficient
         * @param value coefficient to be set
         */
        void setObstacleForceCoe(float value);

        /**
         * @brief getSourceFile gets source file with scene
         * @return source file name
         */
        string getSourceFile() const;

        /**
         * @brief setSourceFile sets scene source file
         * @param value source file
         */
        void setSourceFile(const string &value);

        /**
         * @brief getAllWayPoints gets map with all waypoint in scene
         * @return map with waypoints
         */
        map<int, WayPoint*> getAllWayPoints() const;

        /**
         * @brief setAllWayPoints sets map with waypoints
         * @param value map with waypoints
         */
        void setAllWayPoints(const map<int, WayPoint*> &value);
};
#endif
