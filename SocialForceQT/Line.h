#ifndef LINE_H
#define LINE_H
#include "Point.h"

/**
 * @brief The Line class implements all operations involved with line
 */
class Line{

  private:
	//attribute for start point and end point    
	Point first, second;
    //Ax+By+C=0
	float A,B,C;

  public:
    /**
     * @brief Line constructor without parameter
     * Sets line as (0,0) point
     */
    Line(){
        Point tmp(0, 0);
        setFirst(tmp);
        setSecond(tmp);
    }

    /**
     * @brief Line constructor with parameters
     * @param x begining line point
     * @param y ending line point
     */
    Line(Point x, Point y)
    {
        setFirst(x);
        setSecond(y);
		computeEquationForm();
    }

    /**
     * @brief computeEquationForm computes equation parameters
     * Ax + By + C = 0
     */
    void computeEquationForm()
    {
        A = first.getY() - second.getY();
        B = second.getX() - first.getX();
        C = first.getY() * (first.getX() - second.getX()) - first.getX() * (first.getY() - second.getY());
    }

    /**
     * @brief copy method to copy line
     * @param tmp line to copy
     */
    void copy(Line tmp){
        first.copy(tmp.getFirst());
        second.copy(tmp.getSecond());
		computeEquationForm();    
	}

    /**
     * @brief getAParam gets A param
     * @return A param
     */
	float getAParam() { return A; }

    /**
     * @brief getAParam gets B param
     * @return B param
     */
    float getBParam() { return B; }

    /**
     * @brief getAParam gets C param
     * @return C param
     */
    float getCParam() { return C; }

    /**
     * @brief getFirst gets line beginning point
     * @return line beginning point
     */
    Point getFirst() { return first; }

    /**
     * @brief getSecond receives line ending point
     * @return line ending point
     */
    Point getSecond() { return second; }

    /**
     * @brief setFirst sets line beginning point
     * @param x new line beginnig point
     */
    void setFirst(Point x) { first.copy(x); }

    /**
     * @brief setSecond sets line ending point
     * @param y new line ending point
     */
    void setSecond(Point y) { second.copy(y); }
};
#endif
