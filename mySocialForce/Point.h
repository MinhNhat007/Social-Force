#ifndef POINT_H
#define POINT_H

//class Point
//contains all methods involvesd with Point
class Point{
    private:
        float x, y;
    public:
        //constructor withou parameter
        Point(){ setX(x); setY(0.0);}

        //constructor with parameters
        Point(float x, float y){ setX(x); setY(y);}

        //method
        void copy(Point point){
            x = point.getX();
            y = point.getY();
        }

        //get/set methods
        float getX(){ return x;}
        float getY(){ return y;}
        void setX(float x){ this->x = x;}
        void setY(float y){ this->y = y;}
};
#endif