#ifndef NEARAGENT_H
#define NEARAGENT_H

#include "Agent.h"

class NearAgent
{
    public:
        NearAgent(Agent* sourceAgent, Agent* nearAgent);
        Agent* getAgent();
        float getDistance();
    protected:

    private:
        float distance;
        Agent* agent;
};

#endif // NEARAGENT_H
