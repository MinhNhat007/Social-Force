#include "Agent.h"
#include <iostream>
#define oo 100000000
using namespace std;

int Agent::currentID = 0;
default_random_engine generator;

float Agent::getRadius() const
{
    return radius;
}

Vector2 Agent::getCurrentSpeed() const
{
    return currentSpeed;
}

float Agent::getActualForce() const
{
    return actualForce;
}

Agent::Agent(Point position){
    setID(0);
    setRadius();
    setDesiredSpeed();
    setPosition(position);
    setRelaxationTime();

}

void Agent::addWayPoint(WayPoint* wp) {
	wayPoints.push_back(wp);
	destination = wayPoints.front();
}


void Agent::makeAMove(vector<Wall> walls, vector<Agent> agents, float stepTime,
                      float destForceCoe,float obstacleForceCoe,float agentsForceCoe){
    Vector2 acceleration;
    Vector2 forceWithWall = wallInteractForce(walls)*obstacleForceCoe;
    Vector2 forceByThemselfe = internalForce()*destForceCoe;
    Vector2 forceWithOthers = agentInteractForce(agents)*agentsForceCoe;

    Vector2 tmpAcceleration = forceWithOthers + forceWithWall;
    acceleration = tmpAcceleration + forceByThemselfe;

    this->actualForce = tmpAcceleration.getLength();
    currentSpeed = currentSpeed*0.5 + acceleration * stepTime;
    if (currentSpeed.getLength() > desiredSpeed){
        currentSpeed = currentSpeed.normalize();
        currentSpeed = currentSpeed*desiredSpeed;
    }

    Vector2 tmpSpeed = currentSpeed * stepTime;

    float tmpX = this->position.getX() + tmpSpeed.getX();
    float tmpY = this->position.getY() + tmpSpeed.getY();

    position.setX(tmpX);
    position.setY(tmpY);
}

Vector2 Agent::agentInteractForce(vector<Agent> agents){
    //float A = 4.5; is in book but not used there
    // parameters from book Helbing(2009)
    float n_prim = 3.0;
    float n = 2.0;
    float gamma = 0.35;
    float lambda = 2.0;

    Vector2 f_ij(0, 0);
    for (Agent agent: agents){
        //ommit the same agent and agents which reached destination(id==-1)
        if (this->id != agent.id && agent.id != -1){
            Vector2 distance_ij(agent.getPosition(), this->getPosition());

            float d = distance_ij.getLength();
            if (d > 0.02)  //if distance between agnets is too long, this agent is ommited
                continue;

            Vector2 e_ij = distance_ij.normalize();
            Vector2 tmpV = this->currentSpeed - agent.currentSpeed;

            // compute interaction direction t_ij
            Vector2 D_ij = tmpV*lambda;
            D_ij = D_ij + e_ij;

            float B = D_ij.getLength()*gamma;

            Vector2 t_ij = D_ij;
            t_ij = t_ij.normalize();
            Vector2 n_ij = t_ij.unitLeftOrientedVector();

            float theta = t_ij.getAngle(e_ij);

            float tmpCoefficient = exp(-d/B);//exp(-d/B);
            //f_v
            float tmpF_v = exp(-(n_prim * B * theta) * (n_prim * B * theta));
            Vector2 f_v = t_ij*tmpF_v;
            
            //f_theta
            float tmpF_theta = exp(-(n*B*theta)*(n*B*theta));
            Vector2 f_theta = n_ij*tmpF_theta;
            //calculate result
            Vector2 tmpF_ij = f_v+f_theta;
            f_ij = f_ij + tmpF_ij*tmpCoefficient;
        }
    }
    return f_ij;
}


Vector2 Agent::computeDesiredVector(){
	bool isReached = false;
	Vector2 e_i(0, 0);
	if (destination != NULL) {
		e_i = destination->getForce(position, &isReached);

	}
	if (isReached == true) {
		wayPoints.pop_front();
		if (!wayPoints.empty()) {
			destination = wayPoints.front();
		}
		else destination = NULL;

	}
	
    return e_i;
}

Vector2 Agent::internalForce(){
    float v_o = desiredSpeed;
    Vector2 e_i = computeDesiredVector();
    Vector2 v_i = currentSpeed;
    float T = relaxationTime;
    float tmpT = 1/T;

    Vector2 tmp = e_i * v_o;
    Vector2 tmp1 = tmp - v_i;
    Vector2 res = tmp1 * tmpT;

    return res;
}

Vector2 Agent::wallInteractForce(vector<Wall> walls){
    const int a = 1.3;
    const float b = 0.8;


    Vector2 vectorInteractWithWall;

    //include only the neares wall
    float minDistance = INFINITY;
        float dw = 0.0;
        for (Wall wall : walls) {
            Point tmpPoint = wall.getNearestPoint(this->getPosition());
            Vector2 tmpVector(tmpPoint, this->getPosition());
            dw = tmpVector.getLength();

            if (dw < minDistance) {
                minDistance = dw;
                vectorInteractWithWall = tmpVector;
            }

        }

        minDistance = minDistance - radius;

        Vector2 vectorNomalization = vectorInteractWithWall.normalize();

        float forceInteractWithWalls = a*exp(-minDistance/b);
        return (vectorNomalization*forceInteractWithWalls);

}

bool Agent::isReachDestination(){
	if (destination == NULL)
		return true;
	else
		return false;
}

int Agent::getID(){
    return this->id;
}

Point Agent::getPosition(){
    return position;
}

WayPoint* Agent::getDestination(){
    return destination;
}

void Agent::setID(int x){
    if (x == 0){
        id = currentID;
        currentID++;
    }
    else id = x;
}


void Agent::setRadius(){
    radius = 0.2;
}

void Agent::setPosition(Point tmp){
    position.copy(tmp);
}

void Agent::setRelaxationTime(){
    normal_distribution<float> distribution(0.54F, 0.05F); // Generate random value of mean 0.54 and standard deviation 0.05
    relaxationTime = distribution(generator);
}

void Agent::setDesiredSpeed(){
    normal_distribution<float> distribution(1.29F, 0.19F); // Generate random value of mean 1.29 and standard deviation 0.19
    desiredSpeed = distribution(generator);
}
