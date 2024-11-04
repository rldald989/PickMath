#include <iostream>
#include <string>
#include <math.h>
#include "files/Matrix/Matrix2.h"
#include "files/Matrix/Matrix3.h"

std::string vector3_to_string(Vector3 a){
    return std::string(std::to_string(a.x) + " " + std::to_string(a.y) + " " + std::to_string(a.z));
}

std::string vector2_to_string(Vector2 a){
    return std::string(std::to_string(a.m_x) + " " + std::to_string(a.m_y));
}

float det2(Matrix2 mat2){
    return (mat2.a * mat2.d) - (mat2.b * mat2.c);
}

float det3(Matrix3 mat3){
    Matrix2 a(mat3.rowB.y, mat3.rowB.z, mat3.rowC.y, mat3.rowC.z);
    Matrix2 b(mat3.rowB.x, mat3.rowB.z, mat3.rowC.x, mat3.rowC.z);
    Matrix2 c(mat3.rowB.x, mat3.rowB.y, mat3.rowC.x, mat3.rowC.y);
    return (mat3.rowA.x * det2(a)) - (mat3.rowA.y * det2(b)) + (mat3.rowA.z * det2(c));
}

std::string _matrix3_(Matrix3 composition){
    return std::string(
      "[" + vector3_to_string(composition.rowA) + "]\n" +
    + "[" + vector3_to_string(composition.rowB) + "]\n"
    + "[" + vector3_to_string(composition.rowC) + "]\n");
}

Vector2 cramer_solve_transform(Matrix2 transformMat, Vector2 transformedCoords)
{
    float y = det2(Matrix2(transformMat.a, transformedCoords.m_x, transformMat.c, transformedCoords.m_y)) / det2(transformMat);
    float x = det2(Matrix2(transformedCoords.m_x, transformMat.b, transformedCoords.m_y, transformMat.d)) / det2(transformMat);
    return Vector2(x, y);
}

Vector3 cramer_solve_transform_3(Matrix3 transformMat, Vector3 transformedCoords)
{
    float x = det3(
        Matrix3(
            Vector3(transformedCoords.x, transformMat.rowA.y, transformMat.rowA.z),
            Vector3(transformedCoords.y, transformMat.rowB.y, transformMat.rowB.z),
            Vector3(transformedCoords.z, transformMat.rowC.y, transformMat.rowC.z)
        )
    ) / det3(transformMat);

    float y = det3(
        Matrix3(
            Vector3(transformMat.rowA.x, transformedCoords.x, transformMat.rowA.z),
            Vector3(transformMat.rowB.x, transformedCoords.y,  transformMat.rowB.z),
            Vector3(transformMat.rowC.x, transformedCoords.z,  transformMat.rowC.z)
        )
    ) / det3(transformMat);

    float z = det3(
        Matrix3(
            Vector3(transformMat.rowA.x, transformMat.rowA.y, transformedCoords.x),
            Vector3(transformMat.rowB.x, transformMat.rowB.y, transformedCoords.y),
            Vector3(transformMat.rowC.x, transformMat.rowC.y, transformedCoords.z)
        )
    ) / det3(transformMat);

    return Vector3(x, y, z);
}

int main(){
    // if you want to construct a 2x2 matrix you find online, this is the format:
    // [a, b]
    // [c, d]
    // and this is the layout for how to input it: Matrix exampleMat(a, b, c, d); 
    // you're so fucking welcome

    // This is formatted like a regular 3x3 matrix in maths, so don't worry about having to think to much when inputting the values
    // you're so fucking welcome again btw

    // Rotation matrix: [cos(v) -sin(v)]
    //                  [sin(v)  cos(v)]

    Matrix3 transform(
        Vector3(3, 2, -7),
        Vector3(1, 2, -4),
        Vector3(4, 0, 1)
    );

    Vector3 transformed(4, 2, 5);

    std::cout << vector3_to_string(cramer_solve_transform_3(transform, transformed)) << std::endl;

    return 0;
}

//g++ main.cpp files/Vector/Vector2.cpp files/Vector/Vector3.cpp files/Matrix/Matrix2.cpp files/Matrix/Matrix3.cpp -o main