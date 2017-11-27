#include "NearAgent.h"

NearAgent::NearAgent(Agent* sourceAgent, Agent* nearAgent)
{
    Vector2 distanceVec = sourceAgent->getPosition() + nearAgent->getPosition();
    distance = distanceVec.length();
    agent = nearAgent;
}

Agent* NearAgent::getAgent()
{
    return agent;
}

float NearAgent::getDistance()
{
    return distance;
}
