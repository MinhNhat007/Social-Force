#include "SocialForce.h"
SocialForce::SocialForce(){
    myWalls.clear();
    myAgents.clear();
}
void SocialForce::createWalls(){
    // Upper Wall
    Point first(0.5, -0.7);
    Point second(0.5, -0.1);
    Line line(first, second);
    Wall wall(line);
    addWall(wall);

    // Lower Wall
    Point first1(0.5, 0.7);
    Point second1(0.5, 0.1);
    Line line1(first1, second1);
    Wall wall1(line1);
    addWall(wall1);

    Point first2(0.5, 0.7);
    Point second2(-1.0, 0.7);
    Line line2(first2, second2);
    Wall wall2(line2);
    addWall(wall2);

    Point first3(0.5, -0.7);
    Point second3(-1.0, -0.7);
    Line line3(first3, second3);
    Wall wall3(line3);
    addWall(wall3);
}

void SocialForce::addWall(Wall tmp){
    myWalls.push_back(tmp);
}

vector<Wall> SocialForce::getWalls(){
    return myWalls;
}

void SocialForce::createAgents(int quantity){
    for (int i = 0; i < quantity; i++){
        float tmpX = randomFloat(-20.3F, -5.0);
        float tmpY = randomFloat(-5.0, 5.0);
        Point currentPoint(tmpX, tmpY);

        float tmpX1 = randomFloat(25.0, 30.0);
        float tmpY1 = randomFloat(-5.0, 5.0);
        Point destinationPoint(tmpX1, tmpY1);

        Agent agent(currentPoint, destinationPoint);
        addAgent(agent);
    }
}

void SocialForce::addAgent(Agent tmp){
    myAgents.push_back(tmp);
}

void SocialForce::nextState(float stepTime){
    int numberOfAgent = myAgents.size();
    for (int i = 0; i < numberOfAgent; i++)
        myAgents[i].makeAMove(myWalls, myAgents, stepTime);
        //int j = i + 1;
}   

vector<Agent> SocialForce::getAgents(){
    return myAgents;
}