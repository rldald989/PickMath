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

float Vector3::dot(Vector3 &other)
{
    return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3 Vector3::cross(Vector3 &other)
{
    return Vector3(
        (y * other.z) - (other.y * z), 
        (z * other.x) - (other.z * x),
        (x * other.y) - (other.x - y)
    );
}

std::string Vector3::to_string(Vector3 a)
{
    return std::string(std::to_string(a.x) + " " + std::to_string(a.y) + " " + std::to_string(a.z));
}