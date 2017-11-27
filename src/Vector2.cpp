#include "Vector2.h"

Vector2::Vector2(void)
{
}

Vector2::Vector2(float X, float Y){
    this->X = X;
    this->Y = Y;
}

// Returns the length of the vector
float Vector2::length(){
    return sqrt(X * X + Y * Y);
}

// Normalizes the vector
Vector2 Vector2::normalize(){
    Vector2 vector;
    float length = this->length();

    if(length != 0){
        vector.X = X/length;
        vector.Y = Y/length;
    }

    return vector;
}

float Vector2::getX()
{
    return X;
}

float Vector2::getY()
{
    return Y;
}

void Vector2::setX(float X)
{
    this.X = X;
}

void Vector2::setY(float Y)
{
    this.Y = Y;
}

Vector2 & Vector2::operator+(const Vector2 & other)
{
    return Vector2(this.getX()+other.getX(),this.getY()+other.getY());

}

Vector2 & Vector2::operator-(const Vector2 & other)
{
    return Vector2(this.getX()-other.getX(),this.getY()-other.getY());
}

Vector2::~Vector2(void)
{
}


