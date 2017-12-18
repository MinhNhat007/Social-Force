#include "Vector2.h"

Vector2::Vector2(void){
    X = 0;
    Y = 0;
}

Vector2::Vector2(float X, float Y){
    this->X = X;
    this->Y = Y;
}

Vector2::Vector2(Point first, Point second){
    X = second.getX() - first.getX();
    Y = second.getY() - first.getY();
}

// Returns the length of the vector
float Vector2::getLength(){
    return sqrt(X * X + Y * Y);
}

// Normalizes the vector
Vector2 Vector2::normalize(){
    Vector2 vector;
    float length = this->getLength();

    if (length != 0){
        vector.X = X / length;
        vector.Y = Y / length;
    }

    return vector;
}

float Vector2::getX(){
    return X;
}

float Vector2::getY(){
    return Y;
}

void Vector2::setX(float X){
    this->X = X;
}

void Vector2::setY(float Y){
    this->Y = Y;
}

float Vector2::getAngle(Vector2 other){
    float dot, det;
    dot = X * other.getX() + Y * other.getY(); // dot product between [x1, y1] and [x2, y2]
    det = X * other.getY() - Y * other.getX(); // determinant

    return atan2(det, dot); // the angle may be negative number
}

Vector2 Vector2::unitLeftOrientedVector(){
    Vector2 v(-Y, X);
    return v.normalize();
}

Vector2 Vector2::operator+(const Vector2& other){
    return Vector2(this->X + other.X, this->Y + other.Y);
}

Vector2 Vector2::operator-(const Vector2& other){
    return Vector2(this->X - other.X, this->Y - other.Y);
}

Vector2 Vector2::operator*(const float& param){
    return Vector2(this->X * param, this->Y * param);
}

Vector2& Vector2::operator=(Vector2 other){
    this->X = other.X;
    this->Y = other.Y;
    return *this;
}

Vector2::~Vector2(void){
}