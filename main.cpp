#include <iostream>
#include <string>
#include "files/Matrix/Matrix2.h"
#include "files/Matrix/Matrix3.h"

std::string vector3_to_string(Vector3 a){
    return std::string(std::to_string(a.x) + " " + std::to_string(a.y) + " " + std::to_string(a.z));
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

int main(){

    Vector3 a(1.f, 1.f, 1.f);

    // if you want to construct a 2x2 matrix you find online, this is the format:
    // [a, b]
    // [c, d]
    // and this is the layout for how to input it: Matrix exampleMat(a, b, c, d); 
    // you're so fucking welcome

    Matrix2 shear(1, 1, 0, 1);
    Matrix2 rotation(0, -1, 1, 0);

    // This is formatted like a regular 3x3 matrix in maths, so don't worry about having to think to much when inputting the values
    // you're so fucking welcome again btw
    Matrix3 _a
    (
        Vector3(0, -2, 2), 
        Vector3(5, 1, 5), 
        Vector3(1, 4, -1)
    );

    Matrix3 _b
    (
        Vector3(0, 1, 2), 
        Vector3(3, 4, 5), 
        Vector3(6, 7, 8)
    );

    Matrix3 composition = _a *_b;
    Vector3 shearResult = a * composition;

    std::cout << _matrix3_(composition) << std::endl;

    std::cout << det3(_a) << std::endl;

    return 0;
}