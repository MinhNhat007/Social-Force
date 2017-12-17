#ifndef LINE_H
#define LINE_H
#include "Point.h"
//class Line implement all operations involved with line
class Line{

  private:
	//attribute for start point and end point    
	Point first, second;
	//y = ax + b
	float A,B,C;

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
		computeEquationForm();
    }

    // Ax + By + C = 0
    void computeEquationForm()
    {
        A = first.getY() - second.getY();
        B = second.getX() - first.getX();
        C = first.getY() * (first.getX() - second.getX()) - first.getX() * (first.getY() - second.getY());
    }

    //copy method
    void copy(Line tmp){
        first.copy(tmp.getFirst());
        second.copy(tmp.getSecond());
		computeEquationForm();    
	}

    //get/set methods
	float getAParam() { return A; }
    float getBParam() { return B; }
    float getCParam() { return C; }
    Point getFirst() { return first; }
    Point getSecond() { return second; }
    void setFirst(Point x) { first.copy(x); }
    void setSecond(Point y) { second.copy(y); }
};
#endif
