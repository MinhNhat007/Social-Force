#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include "Point.h"

// 2D Vector
class Vector2{
    private:
        float X, Y;

    public:
        //instructor
        Vector2(void);
        Vector2(float X, float Y);
        Vector2(Point, Point);
        ~Vector2(void);
        
        //get length of vector
        float getLength();
        //normalize of vector
        Vector2 normalize();
        //get unit left vector
        Vector2 unitLeftOrientedVector();
        //get angel between 2 vectors
        float getAngle(Vector2 other);

        //get/set methods
        float getX();
        float getY();
        void setX(float X);
        void setY(float Y);
    
        //operator
        Vector2 operator+(Vector2 );
        Vector2 operator-(Vector2 );
        Vector2 operator*(float param);
        Vector2 &operator=(Vector2 other);
};

#endif // VECTOR2_H