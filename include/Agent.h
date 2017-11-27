#ifndef AGENT_H
#define AGENT_H

#include "Vector2.h"
#include <vector>
class Agent
{
    public:
        Agent(Vector2 velocity, Vector2 position);
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
};

#endif // AGENT_H
