#ifndef AGENT_H
#define AGENT_H

#include "Vector2.h"
#include <vector>
class Agent
{
    public:
        Agent(Vector2 velocity, Vector2 position);
        Vector2 computeVelocity();
        Vector2 computeDirVel();
        Vector2 computeObstaclesVel();
        Vector2 computeOtherAgentsVel();
        Vector2 getVelocity();
        Vector2 getPosition();
        void setVelocity(Vector2 v);
        void setPosition(Vector2 v);
    protected:
        std::vector<NearAgent> nearAgents;
        std::vector<NearObstacle> nearObstacles;


    private:
        Vector2 velocity;
        Vector2 position;
        Vector2 nextVelocity;
        Vector2 nextPosition;
        float prefSpeed;
        float relaxTime; //relaxation time
        Vector2 prefDirection; //prefered direction of motion

};

#endif // AGENT_H
