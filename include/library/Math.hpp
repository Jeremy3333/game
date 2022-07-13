#pragma once

// include public libraries
#include <iostream>

class Vector2f
{
public:
    Vector2f(float p_x, float p_y);
    float x, y;
    void print()
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }
};

Vector2f operator-(const Vector2f &lhs, const Vector2f &rhs);
Vector2f operator+(const Vector2f &lhs, const Vector2f &rhs);
Vector2f operator+=(Vector2f &lhs, const Vector2f &rhs);
Vector2f operator/(const Vector2f &lhs, float rhs);
Vector2f operator*(const Vector2f &lhs, float rhs);
Vector2f operator*(float rhs, const Vector2f &lhs);
double distance(Vector2f v1, Vector2f v2);