#pragma once

#include "../Vector/Vector2.h"

// x[a c] + y[b d] = [ax + by]
//                   [cx + dy]   

class Matrix2
{
private:
    /* data */
public:
    float a, b, c, d;
    float determinant;

    Matrix2(float _a, float _b, float _c, float _d);
    ~Matrix2();

    friend Vector2 operator*(const Vector2& v, const Matrix2& m);
    
    Matrix2 operator*(Matrix2& other);

};