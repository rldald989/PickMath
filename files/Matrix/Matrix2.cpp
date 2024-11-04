#include "Matrix2.h"

Matrix2::Matrix2(float _a, float _b, float _c, float _d): a(_a), b(_b), c(_c), d(_d), determinant((a * d) - (b * c)) 
{
}

Matrix2::~Matrix2()
{
}

Vector2 operator*(const Vector2 &v, const Matrix2 &m)
{
    return Vector2((m.a * v.m_x) + (m.b * v.m_y), (m.c * v.m_x) + (m.d * v.m_y));
}

Matrix2 Matrix2::operator*(Matrix2 &other)
{
    Vector2 ac(other.a, other.c);
    Vector2 bd(other.b, other.d);
    Vector2 resultA = ac * *this;
    Vector2 resultB = bd * *this;
    return Matrix2(ac.m_x, bd.m_x, ac.m_y, bd.m_y);
}