#include "Vector2.h"

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{

}

Vector2::~Vector2()
{

}

Vector2 Vector2::operator+(Vector2 &other)
{
    return Vector2(m_x + other.m_x, m_y + other.m_y);
}

Vector2 Vector2::operator-(Vector2 &other)
{
    return Vector2(m_x - other.m_x, m_y - other.m_y);
}

Vector2 Vector2::operator*(Vector2 &other)
{
    return Vector2(m_x * other.m_x, m_y * other.m_y);
}

Vector2 Vector2::operator/(Vector2 &other)
{
    return Vector2(m_x / other.m_x, m_y / other.m_y);
}

float Vector2::dot(Vector2 &other)
{
    return (m_x * other.m_x) + (m_y * other.m_y);
}

float Vector2::det(Vector2 &other)
{
    return (m_x * other.m_x) - (m_y * other.m_y);
}
