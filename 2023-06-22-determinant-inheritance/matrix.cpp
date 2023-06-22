#include "matrix.h"

template <std::size_t R, std::size_t C>
Matrix<R, C>::Matrix() {
    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            data[row][column] = 0;
        }
    }
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator+(const Matrix<R, C>& lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs.data[row][column] + rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator+(double lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs + rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator+(const Matrix<R, C>& lhs, double rhs) {
    return rhs + lhs;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator-(const Matrix<R, C>& lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs.data[row][column] - rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator-(double lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs - rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator-(const Matrix<R, C>& lhs, double rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs.data[row][column] - rhs;
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator*(const Matrix<R, C>& lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs.data[row][column] * rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator*(double lhs, const Matrix<R, C>& rhs) {
    Matrix<R, C> returnMatrix;

    for (std::size_t row = 0; row < R; row++) {
        for (std::size_t column = 0; column < C; column++) {
            returnMatrix.data[row][column] = lhs * rhs.data[row][column];
        }
    }

    return returnMatrix;
}

template <std::size_t R, std::size_t C>
Matrix<R, C> operator*(const Matrix<R, C>& lhs, double rhs) {
    return rhs * lhs;
}

template <std::size_t R, std::size_t C>
std::array<double, C>& Matrix<R, C>::operator[](std::size_t row){
    return data[row];
}

template <std::size_t R, std::size_t C>
std::ostream& operator<<(std::ostream& out, const Matrix<R, C>& matrix) {
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

