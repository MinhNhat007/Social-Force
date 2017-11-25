#include "Pedestrian.h"

Pedestrian::Pedestrian(double posX, double posY, double vX0, double vY0)
{
    velocity[0] = vX0;
    velocity[1] = vY0;
    position[0] = posX;
    position[1] = posY;
}

double Pedestrian::getVelocityX()
{
    return velocity[0];
}

double Pedestrian::getVelocityY()
{
    return velocity[1];
}

void Pedestrian::setVelocityX(double vX)
{
    velocity[0] = vX;
}

void Pedestrian::setVelocityY(double vY)
{
    velocity[1] = vY;
}

double Pedestrian::getPositionX()
{
    return position[0];
}

double Pedestrian::getPositionY()
{
    return position[1];
}

void Pedestrian::setPositionX(double posX)
{
    position[0] = posX;
}

void Pedestrian::setPositionY(double posY)
{
    position[1] = posY;
}
