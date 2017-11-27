#include "NearAgent.h"

NearAgent::NearAgent(Agent* sourceAgent, Agent* nearAgent)
{
    // TO DO
    //distance = sourceAgent->getPosition()
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
