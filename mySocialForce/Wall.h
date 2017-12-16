#ifndef WALL_H
#define WALL_H

#include "Line.h"

//Wall class
//All methods involved with wall
class Wall{
    private:
        //data is stored by a line
        Line line;
    public:
        //contructor with parameters
        Wall(Line line){ this->line.copy(line); } 

        //find the nearest point with one point
        Point getNearestPoint(Point);
        
        //get method
        Line getLine(){
            return line;
        }
};

#endif