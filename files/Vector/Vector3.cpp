#include "Vector3.h"

Vector3::Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z)
{
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 &other)
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(Vector3 &other)
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(Vector3 &other)
{
    return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator/(Vector3 &other)
{
    return Vector3(x * other.x, y * other.y, z * other.z);
}
