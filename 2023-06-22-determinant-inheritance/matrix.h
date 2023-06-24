#include <array>
#include <cmath>
#include <iostream>

#if !defined(DETERMINANT_INHERITANCE_H)
#define DETERMINANT_INHERITANCE_H

template <std::size_t R, std::size_t C>
class Matrix {
   protected:
    std::array<std::array<double, C>, R> data;

   public:
    Matrix() {
        for (auto& row : data) {
            std::fill(row.begin(), row.end(), 0);
        }
    }

    Matrix(std::array<std::array<double, C>, R> matrix) : data(matrix) {}

    constexpr std::array<double, C>& operator[](const std::size_t row) {
        return data[row];
    }

    constexpr const std::array<double, C>& operator[](const std::size_t row) const {
        return data[row];
    }

    constexpr std::array<double, C>& at(const std::size_t row) {
        return data.at(row);
    }

    constexpr const std::array<double, C>& at(const std::size_t row) const {
        return data.at(row);
    }

    constexpr double& at(const std::size_t row, const std::size_t column) {
        return data.at(row).at(column);
    }

    constexpr const double& at(const std::size_t row, const std::size_t column) const {
        return data.at(row).at(column);
    }

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix[row][column] = lhs.data[row][column] + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator+(const double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator+(const Matrix& lhs, const double rhs) {
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

    friend Matrix operator-(const double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs - rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator-(const Matrix& lhs, const double rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] - rhs;
            }
        }

        return returnMatrix;
    }

    template <std::size_t T, std::size_t U, std::size_t V>
    friend Matrix<T, V> operator*(const Matrix<T, U>& lhs, const Matrix<U, V>& rhs);

    friend Matrix operator*(const double lhs, const Matrix& rhs) {
        Matrix returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs * rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix operator*(const Matrix& lhs, const double rhs) {
        return rhs * lhs;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        out << "[" << R << 'x' << C << "]\n";

        for (const auto row : matrix.data) {
            for (const auto element : row) {
                out << element << '\t';
            }

            out << '\n';
        }

        out << '\n';

        return out;
    }

    template <std::size_t N>
    friend double const getDeterminant(const Matrix<N, N>& matrix);

    template <std::size_t N>
    friend Matrix<N - 1, N - 1> subMatrix(const Matrix<N, N>& matrix, const std::size_t ignoreRow, const std::size_t ignoreColumn);
};

template <std::size_t N>
using SquareMatrix = Matrix<N, N>;

template <std::size_t N>
SquareMatrix<N - 1> subMatrix(const SquareMatrix<N>& matrix, const std::size_t ignoreRow, const std::size_t ignoreColumn) {
    SquareMatrix<N - 1> returnMatrix;

    int subMatrixRow = 0, subMatrixColumn = 0;

    for (std::size_t matrixRow = 0; matrixRow < N; matrixRow++) {
        for (std::size_t matrixColumn = 0; matrixColumn < N; matrixColumn++) {
            if (matrixRow != ignoreRow && matrixColumn != ignoreColumn) {
                returnMatrix[subMatrixRow][subMatrixColumn++] = matrix[matrixRow][matrixColumn];

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
double const getDeterminant(const SquareMatrix<N>& matrix) {
    double determinant = 0;

    if constexpr (N == 1) {
        determinant = matrix[0][0];
    } else if constexpr (N > 0) {
        for (std::size_t column = 0; column < N; column++) {
            determinant += std::pow(-1, column) * matrix[0][column] * getDeterminant(subMatrix(matrix, 0, column));
        }
    } else {
        throw std::invalid_argument("expected a square matrix");
    }

    return determinant;
}

template <std::size_t R, std::size_t RHC, std::size_t C>
Matrix<R, C> operator*(const Matrix<R, RHC>& lhs, const Matrix<RHC, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            for (std::size_t i = 0; i < RHC; i++) {
                returnMatrix[row][column] += lhs.data[row][i] * rhs.data[i][column];
            }
        }
    }

    return returnMatrix;
}

#endif  // DETERMINANT_INHERITANCE_H