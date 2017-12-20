#ifndef POINT_H
#define POINT_H

#include <math.h>
//class Point
//contains all methods involvesd with Point
class Point{
    protected:
        float x, y;
    public:
        //constructor withou parameter
        Point(){ setX(x); setY(0.0);}

        //constructor with parameters
        Point(float x, float y){ setX(x); setY(y);}


        //method
        //copy method
        void copy(Point point){
            x = point.getX();
            y = point.getY();
        }
        //get distance
        float getDistance(Point point, int coe){
            float tmpX = x - point.getX();
            tmpX = tmpX * tmpX;
            float tmpY = y - point.getY();
            tmpY = tmpY * tmpY;
            
            return sqrt(tmpX + tmpY);
        }

        //check method: upper, lower, on right, on left
        bool isUpper(Point &other){
            if (this->getY() > other.getY())
                return true;
            else
                return false;
        }

        bool isLower(Point &other){
            if (this->getY() < other.getY())
                return true;
            else
                return false;
        }

        bool isOnRight(Point &other){
            if (this->getX() > other.getX())
                return true;
            else
                return false;
        }

        bool isOnLeft(Point &other){
            if (this->getX() < other.getX())
                return true;
            else
                return false;
        }

        Point& operator=(const Point& other)
        {
            this->x = other.x;
            this->y = other.y;

            return *this;
        }

        //get/set methods
        float getX() { return x; }
        float getY() { return y; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
};
#endif