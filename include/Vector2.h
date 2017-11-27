#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

// 2D Vector
class Vector2
{
public:
    Vector2(void);
    Vector2(float X, float Y);
    ~Vector2(void);
    float length();
    Vector2 normalize();
    float getX();
    float getY();
    void setX(float X);
    void setY(float Y);
    Vector2 & operator+(const Vector2 & other);
    Vector2 & operator-(const Vector2 & other);

private:
    float X,Y;
};

#endif // VECTOR2_H
