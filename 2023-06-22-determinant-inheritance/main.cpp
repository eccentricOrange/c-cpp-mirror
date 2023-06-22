#include <iostream>

#include "matrix.h"

int main() {
    static const std::size_t LENGTH = 4;

    SquareMatrix<LENGTH> matrixOne({{{7, -2, 2, 1},
                                     {3, 1, -5, 2},
                                     {2, 2, -5, 3},
                                     {3, -2, 5, 1}}});

    SquareMatrix<LENGTH> matrixTwo({{{1, 2, 3, 4},
                                     {5, 6, 7, 8},
                                     {9, -8, 7, 6},
                                     {5, 4, -3, -2}}});

    Matrix<3, 5> matrixThree({{{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15}}});

    std::cout << "matrixOne "
              << matrixOne;

    std::cout << "matrixTwo "
              << matrixTwo;

    std::cout << "matrixThree "
              << matrixThree;

    std::cout << "matrixOne + matrixTwo "
              << matrixOne + matrixTwo;

    std::cout << "matrixOne - matrixTwo "
              << matrixOne - matrixTwo;

    std::cout << "matrixOne * matrixTwo "
              << matrixOne * matrixTwo;

    std::cout << "matrixThree * 7 "
              << matrixThree * 7;

    std::cout << "determinant of matrixOne: " << getDeterminant(matrixOne) << '\n';

    std::cout << "determinant of matrixTwo: " << getDeterminant(matrixTwo) << '\n';

    std::cout << "matrixOne[2, 3]: " << matrixOne.at(2)[3] << '\n';
}
