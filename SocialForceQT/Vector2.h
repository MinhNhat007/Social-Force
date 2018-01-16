#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include "Point.h"

/**
 * @brief The Vector2 class
 */
class Vector2{
    private:
        float X, Y;

    public:
        /**
         * @brief Vector2 constructor without parameters
         */
        Vector2(void);

        /**
         * @brief Vector2 constructor with parameters
         * @param X parameter
         * @param Y parameter
         */
        Vector2(float X, float Y);

        /**
         * @brief Vector2 construct vector between two points
         * @param p beginning vector point
         * @param p2 ending vector point
         */
        Vector2(Point p, Point p2);

        ~Vector2(void);
        
        /**
         * @brief getLength gets length of vector
         * @return vector length
         */
        float getLength();

        /**
         * @brief returns normal vector
         * @return normal vector
         */
        Vector2 normalize();

        /**
         * @brief unitLeftOrientedVector returns unit left oriented vector
         * @return unit left oriented vector
         */
        Vector2 unitLeftOrientedVector();

        /**
         * @brief getAngle computes angle between two vectors
         * @param other second vector
         * @return angle
         */
        float getAngle(Vector2 other);

        /**
         * @brief getX receives x parameter
         * @return x parameter
         */
        float getX();

        /**
         * @brief getY receives y parameter
         * @return y parameter
         */
        float getY();

        /**
         * @brief setX sets x parameter
         * @param X parameter to be set
         */
        void setX(float X);

        /**
         * @brief setY sets y parameter
         * @param Y parameter to be set
         */
        void setY(float Y);
    
        /**
         * @brief operator +
         * @return
         */
        Vector2 operator+(const Vector2&);
        Vector2 operator-(const Vector2&);

        /**
         * @brief operator *
         * @return
         */
        Vector2 operator*(const float&);

        /**
         * @brief operator =
         * @param other
         * @return
         */
        Vector2& operator=(Vector2 other);
}; 
#endif // VECTOR2_H
