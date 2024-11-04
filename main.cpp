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
    return det2(a) - det2(b) + det2(c);
}

std::string _matrix3_(Matrix3 composition){
    return std::string(
      "[" + vector3_to_string(composition.rowA) + "]\n" +
    + "[" + vector3_to_string(composition.rowB) + "]\n"
    + "[" + vector3_to_string(composition.rowC) + "]\n");
}

Vector2 camer_solve_transform(Matrix2 transformMat, Vector2 transformedCoords)
{
    float y = det2(Matrix2(transformMat.a, transformedCoords.m_x, transformMat.c, transformedCoords.m_y)) / det2(transformMat);
    float x = det2(Matrix2(transformedCoords.m_x, transformMat.b, transformedCoords.m_y, transformMat.d)) / det2(transformMat);
    return Vector2(x, y);
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

    Vector2 a_(4, 3);
    Vector2 b_(1, 2);

    Matrix2 transform(cosf(30), -sinf(30), sinf(30), cosf(30));

    Vector2 transformedVector = a_ * transform;

    std::cout << "Vector3 originalVector: " << vector2_to_string(a_) << std::endl;
    std::cout << "Vector3 transformedVector: " << vector2_to_string(transformedVector) << std::endl;
    std::cout << "Vector3 solvedVector: " << vector2_to_string(camer_solve_transform(transform, transformedVector)) << std::endl;

    return 0;
}