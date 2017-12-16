#include "Agent.h"
using namespace std;

int Agent::currentID = 0;
default_random_engine generator;
Agent::Agent(Point position, Point destination){
    setID();
    setRadius();
    setDesiredSpeed();
    setPosition(posistion);
    setDestination(destination);
}

void Agent::setID(){
    id = currentID;
    currentID++;
}

void Agent::setRadius(){
    radius = 0.2;
}

void Agent::setPosition(Point tmp){
    posistion.copy(tmp);
}

void Agent::setDestination(Point tmp){
    destination.copy(tmp);
}

void Agent::setDesiredSpeed(){
    normal_distribution<float> distribution(1.29F, 0.19F); // Generate random value of mean 1.29 and standard deviation 0.19
    desiredSpeed = distribution(generator);
}

void Agent::makeAMove(vector<Wall> walls, vector<Agent> agents, float stepTime){
    vectorMath acceleration;

    vectorMath forceWithWall = wallInteractForce(walls);
}

vectorMath Agent::wallInteractForce(vector<Wall> walls){
    const int a = 3;
    const float b = 0.1;

    //calculate nearest point
    Point nearestPoint = getNearestPointFromWalls(walls);
    return *(new vectorMath());
}


Point getNearestPointFromWalls(vector<Wall> walls){
    Point res;
    for (Wall wall: walls){
        Point point = wall.getNearestPoint(this.posistion)
    }
}