#include <iostream>
#include <array>
#include <cmath>

#if !defined(DETERMINANT_INHERITANCE_H)
#define DETERMINANT_INHERITANCE_H

template <std::size_t R, std::size_t C>
class Matrix {
   protected:
    std::array<std::array<double, C>, R> data;

   public:
    Matrix() {
        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                data[row][column] = 0;
            }
        }
    }
    Matrix(std::array<std::array<double, C>, R> matrix) : data(matrix) {}

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator+(double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator+(const Matrix& lhs, double rhs) {
        return rhs + lhs;
    }

    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] - rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator-(double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs - rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator-(const Matrix& lhs, double rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] - rhs;
            }
        }

        return returnMatrix;
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = 0;

                for (std::size_t i = 0; i < C; i++) {
                    returnMatrix.data[row][column] += lhs.data[row][i] * rhs.data[i][column];
                }
            }
        }

        return returnMatrix;
    }

    friend Matrix operator*(double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs * rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator*(const Matrix& lhs, double rhs) {
        return rhs * lhs;
    }

    std::array<double, C>& operator[](std::size_t row) {
        return data[row];
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        out << "[" << R << 'x' << C << "]\n";

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                out << matrix.data[row][column] << '\t';
            }

            out << '\n';
        }

        out << '\n';

        return out;
    }

    template <std::size_t N>
    friend double getDeterminant(Matrix<N, N> matrix);

    template <std::size_t N>
    friend Matrix<N - 1, N - 1> subMatrix(Matrix<N, N> matrix, std::size_t ignoreRow, std::size_t ignoreColumn);
};

template <std::size_t N>
using SquareMatrix = Matrix<N, N>;

template <std::size_t N>
SquareMatrix<N - 1> subMatrix(SquareMatrix<N> matrix, std::size_t ignoreRow, std::size_t ignoreColumn) {
    SquareMatrix<N - 1> returnMatrix;

    int subMatrixRow = 0, subMatrixColumn = 0;

    for (std::size_t matrixRow = 0; matrixRow < N; matrixRow++) {
        for (std::size_t matrixColumn = 0; matrixColumn < N; matrixColumn++) {
            if (matrixRow != ignoreRow && matrixColumn != ignoreColumn) {
                returnMatrix[subMatrixRow][subMatrixColumn++] = matrix.data[matrixRow][matrixColumn];

                if (subMatrixColumn == N - 1) {
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
    double determinant = 0;

    if constexpr (N == 1) {
        determinant = matrix.data[0][0];
    } else if constexpr (N == 2) {
        determinant = matrix.data[0][0] * matrix.data[1][1] - matrix.data[0][1] * matrix.data[1][0];
    } else if constexpr (N > 0) {
        for (std::size_t column = 0; column < N; column++) {
            determinant += std::pow(-1, column) * matrix.data[0][column] * getDeterminant(subMatrix(matrix, 0, column));
        }
    } else {
        throw std::invalid_argument("expected a square matrix");
    }

    return determinant;
}

#endif  // DETERMINANT_INHERITANCE_H