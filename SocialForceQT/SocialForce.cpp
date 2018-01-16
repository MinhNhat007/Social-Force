#include "SocialForce.h"
#include <iostream>
using namespace std;

float SocialForce::randomFloat(float lowerBound, float upperBound){
    return (lowerBound + (static_cast<float>(rand()) / RAND_MAX) * (upperBound - lowerBound));
}

float SocialForce::getDestForceCoe() const
{
    return destForceCoe;
}

void SocialForce::setDestForceCoe(float value)
{
    destForceCoe = value;
}

float SocialForce::getAgentsForceCoe() const
{
    return agentsForceCoe;
}

void SocialForce::setAgentsForceCoe(float value)
{
    agentsForceCoe = value;
}

float SocialForce::getObstacleForceCoe() const
{
    return obstacleForceCoe;
}

void SocialForce::setObstacleForceCoe(float value)
{
    obstacleForceCoe = value;
}

string SocialForce::getSourceFile() const
{
    return sourceFile;
}

void SocialForce::setSourceFile(const string &value)
{
    sourceFile = value;
}

map<int, WayPoint*> SocialForce::getAllWayPoints() const
{
    return allWayPoints;
}

void SocialForce::setAllWayPoints(const map<int, WayPoint*> &value)
{
    allWayPoints = value;
}

SocialForce::SocialForce(){
    myWalls.clear();
    myAgents.clear();
}

void SocialForce::addWall(Wall tmp){
    myWalls.push_back(tmp);
}

vector<Wall> SocialForce::getWalls(){
    return myWalls;
}

void SocialForce::createAgents(int quantity){
	WayPoint* w1 = new WayPoint(1, 0.52, 0.0, 0.05);
	WayPoint* w2 = new WayPoint(2, 0.8, 0.5, 0.1);
    for (int i = 0; i < quantity; i++){
        float tmpX = randomFloat(-0.95F, 0.45);
        float tmpY = randomFloat(-0.65F, 0.65);

        Point currentPoint(tmpX, tmpY);

        Agent agent(currentPoint);
		agent.addWayPoint(w1);
		agent.addWayPoint(w2);
        addAgent(agent);
    }
}

void SocialForce::addAgent(Agent tmp){
    myAgents.push_back(tmp);
}

void SocialForce::nextState(float stepTime){
    //srand(static_cast<unsigned>(time(0)));
    int numberOfAgent = myAgents.size();
    for (int i = 0; i < numberOfAgent; i++){
        if (myAgents[i].getID() != -1){
            myAgents[i].makeAMove(myWalls, myAgents, stepTime,
                                  destForceCoe,obstacleForceCoe,agentsForceCoe);
            if (myAgents[i].isReachDestination())
                myAgents[i].setID(-1);
            std::cout<<myAgents[i].getActualForce() << endl;
        }
    }
}

vector<Agent> SocialForce::getAgents(){
    return myAgents;
}
