#pragma once

#include "../Vector/Vector3.h"

class Matrix3
{
private:
public:    
    Vector3 rowA;
    Vector3 rowB;
    Vector3 rowC;

    float determinant;

    Matrix3(Vector3 _rowA, Vector3 _rowB, Vector3 _rowC);
    ~Matrix3();

    friend Vector3 operator*(const Vector3& v, const Matrix3& m);

    Matrix3 operator*(Matrix3& other);
};