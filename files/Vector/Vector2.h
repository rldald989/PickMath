#pragma once

class Vector2
{
private:
    
public:
    Vector2(float x, float y);
    ~Vector2();

    float m_x;
    float m_y;

    Vector2 operator+(Vector2& other);
    Vector2 operator-(Vector2& other);
    Vector2 operator*(Vector2& other);
    Vector2 operator/(Vector2& other);
};