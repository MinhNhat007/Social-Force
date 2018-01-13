#include "SocialForce.h"
#include <iostream>
using namespace std;

static float randomFloat(float lowerBound, float upperBound){
    return (lowerBound + (static_cast<float>(rand()) / RAND_MAX) * (upperBound - lowerBound));
}

SocialForce::SocialForce(){
    myWalls.clear();
    myAgents.clear();
}
void SocialForce::createWalls(){
    // lower line thang dung
    Point first(0.5, -0.7);
    Point second(0.5, -0.1);
    Line line(first, second);
    Wall wall(line);
    addWall(wall);

    // upper line thang dung
    Point first1(0.5, 0.7);
    Point second1(0.5, 0.1);
    Line line1(first1, second1);
    Wall wall1(line1);
    addWall(wall1);

    // upper line nam ngang
    Point first2(0.5, 0.7);
    Point second2(-1.0, 0.7);
    Line line2(first2, second2);
    Wall wall2(line2);
    addWall(wall2);

    // lower line nam ngang
    Point first3(0.5, -0.7);
    Point second3(-1.0, -0.7);
    Line line3(first3, second3);
    Wall wall3(line3);
    addWall(wall3);

    // line thang dung
    /*Point first4(-0.5, -0.7);
    Point second4(-0.5, -0.1);
    Line line4(first4, second4);
    Wall wall4(line4);
    addWall(wall4);*/
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

        //float tmpX1 = 0.52;//randomFloat(0.0, 0.0);
        //float tmpY1 = 0.0;//randomFloat(0.0, 0.0);
        //Point destinationPoint(tmpX1, tmpY1);

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
            myAgents[i].makeAMove(myWalls, myAgents, stepTime);
            if (myAgents[i].isReachDestination())
                myAgents[i].setID(-1);
        }
    }
}

vector<Agent> SocialForce::getAgents(){
    return myAgents;
}
