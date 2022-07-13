// include public libraries
#include <cmath>

// include my libraries
#include "library/Math.hpp"

Vector2f::Vector2f() : x(0), y(0)
{
}

Vector2f::Vector2f(float p_x, float p_y)
    : x(p_x), y(p_y)
{
}

Vector2f operator-(const Vector2f &lhs, const Vector2f &rhs)
{
    return Vector2f(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2f operator+(const Vector2f &lhs, const Vector2f &rhs)
{
    return Vector2f(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2f operator+=(Vector2f &lhs, const Vector2f &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

Vector2f operator/(const Vector2f &lhs, float rhs)
{
    return Vector2f(lhs.x / rhs, lhs.y / rhs);
}

Vector2f operator*(const Vector2f &lhs, float rhs)
{
    return Vector2f(lhs.x * rhs, lhs.y * rhs);
}

Vector2f operator*(float rhs, const Vector2f &lhs)
{
    return Vector2f(lhs.x * rhs, lhs.y * rhs);
}

// calculate the distance between two Vector2f
double distance(Vector2f v1, Vector2f v2)
{
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}