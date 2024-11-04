#include <iostream>
#include <string>
#include <math.h>
#include "files/Matrix/Matrix2.h"
#include "files/Matrix/Matrix3.h"

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

    //This is an example
    Matrix3 transform(
        Vector3(3, 2, -7),
        Vector3(1, 2, -4),
        Vector3(4, 0, 1)
    );

    Vector3 transformed(4, 2, 5);

    std::cout << Vector3::to_string(Matrix3::cramer_solve_transform(transform, transformed)) << std::endl;

    return 0;
}