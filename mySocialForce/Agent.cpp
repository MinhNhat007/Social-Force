#include "Agent.h"
#include <iostream>
#define oo 100000000
using namespace std;

int Agent::currentID = 0;
float coefficient = 5.0;
default_random_engine generator;
Agent::Agent(Point position, Point destination){
    setID(0);
    setRadius();
    setDesiredSpeed();
    setPosition(position);
    setDestination(destination);
    setRelaxationTime();
}

void Agent::makeAMove(vector<Wall> walls, vector<Agent> agents, float stepTime){
    Vector2 acceleration;
    Vector2 forceWithWall = wallInteractForce(walls);
    Vector2 forceByThemselfe = internalForce();
    Vector2 forceWithOthers = agentInteractForce(agents);

    Vector2 tmpAcceleration = forceByThemselfe + forceWithWall;
    acceleration = tmpAcceleration + forceWithOthers;

    currentSpeed = currentSpeed + acceleration * stepTime;
    if (currentSpeed.getLength() > desiredSpeed){
        currentSpeed = currentSpeed.normalize();
        currentSpeed = currentSpeed*desiredSpeed;
    }

    //cout << forceWithWall.getLength() << " " << forceByThemselfe.getLength() << " " 
    //    << forceWithOthers.getLength() << endl;
    Vector2 tmpSpeed = currentSpeed * stepTime;

    float tmpX = this->position.getX() + tmpSpeed.getX()/coefficient;
    float tmpY = this->position.getY() + tmpSpeed.getY()/coefficient;

    position.setX(tmpX);
    position.setY(tmpY);
}

Vector2 Agent::agentInteractForce(vector<Agent> agents){
    float A = 4.5;
    float n_prim = 3.0;
    float n = 2.0;
    float gamma = 0.35;
    float lambda = 2.0;

    Vector2 f_ij(0, 0);
    for (Agent agent: agents){
        if (this->id != agent.id && agent.id != -1){
            Vector2 distance_ij(agent.getPosition(), this->getPosition());

            float d = distance_ij.getLength();
            if (d > 0.01)
                continue;

            Vector2 e_ij = distance_ij.normalize();
            Vector2 tmpV = this->currentSpeed - agent.currentSpeed;             
            Vector2 D_ij = tmpV*lambda;
            D_ij = D_ij + e_ij;

            float B = D_ij.getLength()*gamma;

            Vector2 t_ij = D_ij;
            t_ij = t_ij.normalize();
            Vector2 n_ij = t_ij.unitLeftOrientedVector();

            float theta = t_ij.getAngle(e_ij);

            float tmpCoefficient = -A*exp(-d/B);
            //f_v
            float tmpF_v = exp(-(n_prim * B * theta) * (n_prim * B * theta));
            Vector2 f_v = t_ij*tmpF_v;
            
            //f_theta
            float tmpF_theta = exp(-(n*B*theta)*(n*B*theta));
            Vector2 f_theta = n_ij*tmpF_theta;
            //calculate result
            Vector2 tmpF_ij = f_v+f_theta;
            f_ij = f_ij + tmpF_ij;
        }
    }
    return f_ij;
}

Vector2 Agent::computeDesiredVector(){
	

    Vector2 e_i = 
    /*
        How to find way point   
    */
    /*
     po 1s -> nowy punkt -> nowa linia -> czy bedzie spotkac
    */
    return e_i.normalize();
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
    //cout << tmpT << endl;
    //cout << tmp.getX() << " " << tmp.getY() << " " << v_i.getX() 
    //    << " " << v_i.getY() << " " << tmp1.getX() << " " << tmp1.getY() 
    //    << " " << res.getX() << " " << res.getY() << " " << endl;
    return res;
}

Vector2 Agent::wallInteractForce(vector<Wall> walls){
    const int a = 3;
    const float b = 0.1;

    Vector2 vectorInteractWithWall;
    for (Wall wall: walls){
        Point tmpPoint = wall.getNearestPoint(this->getPosition());
        Vector2 tmpVector(this->getPosition(), tmpPoint);
        //if (tmpVector.getLength() > 1)
        //    continue;
        vectorInteractWithWall = vectorInteractWithWall + tmpVector;
    }
    float dw = vectorInteractWithWall.getLength();
    while (dw - radius > 0){
        dw = dw - radius;
    }
    Vector2 vectorNomalization = vectorInteractWithWall.normalize();    

    float forceInteractWithWalls = a*exp(-dw/b);
    return (vectorNomalization*forceInteractWithWalls);

}

/*Point Agent::getNearestPointFromWalls(vector<Wall> walls){
    Point res;
    float minDistance = +oo;

    for (Wall wall: walls){
        Point tmpPoint = wall.getNearestPoint(this->getPosition());
        Vector2 tmpVector(this->getPosition(), tmpPoint); 
        float tmpDistance = tmpVector.getLength();

        if (tmpDistance < minDistance){
            minDistance = tmpDistance;
            res.copy(tmpPoint);
        }
    }
    
    return res;
}*/

bool Agent::isReachDestination(){
    Vector2 tmpVector(position, destination);
    float tmpDistance = tmpVector.getLength();
    if (abs(tmpDistance) < 0.05)
        return true;
    return false;
}

int Agent::getID(){
    return this->id;
}

Point Agent::getPosition(){
    return position;
}

Point Agent::getDestination(){
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

void Agent::setDestination(Point tmp){
    destination.copy(tmp);
}

void Agent::setRelaxationTime(){
    normal_distribution<float> distribution(0.54F, 0.05F); // Generate random value of mean 0.54 and standard deviation 0.05
    relaxationTime = distribution(generator);
}

void Agent::setDesiredSpeed(){
    normal_distribution<float> distribution(1.29F, 0.19F); // Generate random value of mean 1.29 and standard deviation 0.19
    desiredSpeed = distribution(generator);
}