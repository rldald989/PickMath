#include "Matrix3.h"

Matrix3::Matrix3(Vector3 _rowA, Vector3 _rowB, Vector3 _rowC) : 
rowA(_rowA),
rowB(_rowB),
rowC(_rowC), determinant()
{
    
}

Matrix3::~Matrix3()
{
}

Vector3 operator*(const Vector3 &v, const Matrix3 &m)
{
    return Vector3(
        (m.rowA.x * v.x) + (m.rowA.y * v.y) + (m.rowA.z * v.z), 
        (m.rowB.x * v.x) + (m.rowB.y * v.y) + (m.rowB.z * v.z), 
        (m.rowC.x * v.x) + (m.rowC.y * v.y) + (m.rowC.z * v.z));
}

Matrix3 Matrix3::operator*(Matrix3 &other)
{

    Vector3 columnA(other.rowA.x, other.rowB.x, other.rowC.x);
    Vector3 columnB(other.rowA.y, other.rowB.y, other.rowC.y);
    Vector3 columnC(other.rowA.z, other.rowB.z, other.rowC.z);

    Vector3 resultA(columnA * *this);
    Vector3 resultB(columnB * *this);
    Vector3 resultC(columnC * *this);

    Matrix3 reOrdered(
        Vector3(resultA.x, resultB.x, resultC.x),
        Vector3(resultA.y, resultB.y, resultC.y),
        Vector3(resultA.z, resultB.z, resultC.z)
    );

    return reOrdered;
}