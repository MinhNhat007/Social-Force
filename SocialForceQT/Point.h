#ifndef POINT_H
#define POINT_H

#include <math.h>


/**
 * @brief The Point class contains all methods involved with Point
 */
class Point{
    protected:
        float x, y;
    public:
        /**
         * @brief Point constructor without parameter
         */
        Point(){ setX(x); setY(0.0);}

        /**
         * @brief Point constructor with parameters
         * @param x x coordinate
         * @param y y coordinate
         */
        Point(float x, float y){ setX(x); setY(y);}


        /**
         * @brief copy method to copy point
         * @param point point to copy
         */
        void copy(Point point){
            x = point.getX();
            y = point.getY();
        }

        /**
         * @brief getDistance receive distance between two points
         * @param point other point
         * @return distance between points
         */
        float getDistance(Point point){
            float tmpX = x - point.getX();
            tmpX = tmpX * tmpX;
            float tmpY = y - point.getY();
            tmpY = tmpY * tmpY;
            
            return sqrt(tmpX + tmpY);
        }

        /**
         * @brief isUpper method to check if this point is upper than other point
         * @param other point
         * @return true if this point is upper than other point
         */
        bool isUpper(Point &other){
            if (this->getY() > other.getY())
                return true;
            else
                return false;
        }

        /**
         * @brief isLower method to check if this point is lower than other point
         * @param other point
         * @return true if this point is lower than other point
         */
        bool isLower(Point &other){
            if (this->getY() < other.getY())
                return true;
            else
                return false;
        }

        /**
         * @brief isOnRight method to check if this point is on right other point
         * @param other point
         * @return true if this point is on right the other point
         */
        bool isOnRight(Point &other){
            if (this->getX() > other.getX())
                return true;
            else
                return false;
        }


        /**
         * @brief isOnLeft method to check if this point is on left other point
         * @param other point
         * @return true if this point is on left the other point
         */
        bool isOnLeft(Point &other){
            if (this->getX() < other.getX())
                return true;
            else
                return false;
        }

        /**
         * @brief operator =
         * @param other
         * @return
         */
        Point& operator=(const Point& other){
            this->x = other.x;
            this->y = other.y;

            return *this;
        }


        /**
         * @brief getX gets x coordinate
         * @return x coordinate
         */
        float getX() { return x; }

        /**
         * @brief getY gets y coordinate
         * @return y coordinate
         */
        float getY() { return y; }

        /**
         * @brief setX sets new x coordinate
         * @param x new x coordinate
         */
        void setX(float x) { this->x = x; }

        /**
         * @brief setY sets new x coordinate
         * @param y new y coordinate
         */
        void setY(float y) { this->y = y; }
};
#endif
