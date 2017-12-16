#ifndef LINE_H
#define LINE_H
#include "Point.h"
//class Line implement all operations involved with line
class Line
{
  private:
    Point first, second;

  public:
    //constructor withou parameter
    Line()
    {
        Point tmp(0, 0);
        setFirst(tmp);
        setSecond(tmp);
    }

    //constructor with parameters
    Line(Point x, Point y)
    {
        setFirst(x);
        setSecond(y);
    }

    //copy method
    void copy(Line tmp){
        first.copy(tmp.getFirst());
        second.copy(tmp.getSecond());
    }

    //get/set methods
    Point getFirst() { return first; }
    Point getSecond() { return second; }
    void setFirst(Point x) { first.copy(x); }
    void setSecond(Point y) { second.copy(y); }
};
#endif