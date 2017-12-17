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

        //get nearest point
        Point getNearestPoint(Point p){
            float x, y, A, B, C, xo, yo;
            A = line.getAParam();
            B = line.getBParam();
            C = line.getCParam();
            xo = p.getX();
            yo = p.getY();

            Point maxP, minP, first, second;
            first = line.getFirst();
            second = line.getSecond();

            // one point
            if (B == 0 && A == 0){
                y = line.getFirst().getX();
                x = line.getFirst().getY();
            }
            else if (B == 0){ 
                //e.g. x = 3
                if (first.isUpper(second)){
                    maxP = first;
                    minP = second;
                }
                else{
                    maxP = second;
                    minP = first;
                }

                if (yo > maxP.getY()){
                    x = maxP.getX();
                    y = maxP.getY();
                }
                else if (yo < minP.getY()){
                    x = minP.getX();
                    y = minP.getY();
                }
                else{
                    y = yo;
                    x = -C / A;
                }
            }
            else if (A == 0){
                //e.g. y = 3
                if (first.isOnRight(second)){
                    maxP = first;
                    minP = second;
                }
                else{
                    maxP = second;
                    minP = first;
                }

                if (xo > maxP.getX()){
                    x = maxP.getX();
                    y = maxP.getY();
                }
                else if (xo < minP.getX()){
                    x = minP.getX();
                    y = minP.getY();
                }
                else{
                    x = xo;
                    y = -C / B;
                }
            }
            else{
                //e.g. y = 2x + 5
                //write code when point is outside "line square"
                x = (B * B * xo - A * B * yo - A * C) / (B * B + A * A);
                y = (-A * x - C) / B;
            }

            return Point(x, y);
        }

        //get method
        Line getLine(){
            return line;
        }
};

#endif
