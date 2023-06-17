#include <array>
#include <iostream>

template <std::size_t N>
using SquareMatrix = std::array<std::array<double, N>, N>;

template <std::size_t N>
SquareMatrix<N - 1> subMatrix(SquareMatrix<N> matrix, std::size_t ignoreRow, std::size_t ignoreColumn) {
    SquareMatrix<N - 1> returnMatrix;

    int subMatrixRow = 0, subMatrixColumn = 0;
    static const int matrixSize = matrix.size();

    for (std::size_t matrixRow = 0; matrixRow < matrixSize; matrixRow++) {
        for (std::size_t matrixColumn = 0; matrixColumn < matrixSize; matrixColumn++) {

            if (matrixRow != ignoreRow && matrixColumn != ignoreColumn) {
                returnMatrix[subMatrixRow][subMatrixColumn++] = matrix[matrixRow][matrixColumn];

                if (subMatrixColumn == matrixSize - 1) {
                    subMatrixColumn = 0;
                    subMatrixRow++;
                }
            }
        }
    }

    return returnMatrix;
}

template <std::size_t N>
double getDeterminant(SquareMatrix<N> matrix) {
    static const int matrixSize = matrix.size();
    double determinant = 0;

    if constexpr (matrixSize == 1) {
        determinant = matrix[0][0];
    }

    else if constexpr (matrixSize == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    else if constexpr (matrixSize > 0) {
        int sign = 1;

        for (std::size_t dimension = 0; dimension < N; dimension++) {
            determinant += sign * matrix[0][dimension] * getDeterminant(subMatrix(matrix, 0, dimension));
            sign = -sign;
        }
    }

    else {
        throw std::invalid_argument("expected square matrix");
    }

    return determinant;
}

template <std::size_t N>
void printSquareMatrix(SquareMatrix<N> matrix) {
    static const int matrixSize = matrix.size();

    printf("\n[%dx%d] matrix\n", matrixSize, matrixSize);

    for (std::size_t row = 0; row < matrixSize; row++) {
        for (std::size_t column = 0; column < matrixSize; column++) {
            printf("%.0f\t", matrix[row][column]);
        }

        printf("\n");
    }

    printf("\n");
}

int main(int argc, char const* argv[]) {
    static const std::size_t length = 4;

    SquareMatrix<length> matrix = {{{7, -2, 2, 1},
                                    {3, 1, -5, 2},
                                    {2, 2, -5, 3},
                                    {3, -2, 5, 1}}};

    printSquareMatrix(matrix);
    printf("determinant = %.2f\n", getDeterminant(matrix));
}
