#pragma once

#include <string>

class Vector3
{
private:
    
public:
    Vector3(float _x, float _y, float _z);
    ~Vector3();

    float x;
    float y;
    float z;

    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);
    Vector3 operator*(const Vector3& other);
    Vector3 operator/(const Vector3& other);

    float dot(Vector3& other);
    Vector3 cross(Vector3& other);

    static std::string to_string(Vector3 a);
};