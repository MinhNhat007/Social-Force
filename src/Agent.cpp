#include "Agent.h"

Agent::Agent(Vector2 velocity, Vector2 postion)
{
    this.velocity = velocity;
    this.position = position;
}

Vector2 Agent::getVelocity()
{
    return velocity;
}


void Agent::setVelocity(Vector2 velocity)
{
    this.velocity = velocity;
}



Vector2 Agent::getPosition()
{
    return position
}


void Agent::setPosition(Vector2 position)
{
    this.position = position;
}

