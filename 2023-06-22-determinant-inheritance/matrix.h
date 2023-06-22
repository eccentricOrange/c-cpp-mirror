#include <array>
#include <iostream>

#if !defined(DETERMINANT_INHERITANCE_H)
#define DETERMINANT_INHERITANCE_H

template <std::size_t R, std::size_t C>
class Matrix {
   protected:
    std::array<std::array<double, C>, R> data;

   public:
    Matrix();
    Matrix(std::array<std::array<double, C>, R> matrix) : data(matrix) {}

    friend Matrix<R, C> operator+(const Matrix& lhs, const Matrix& rhs);
    friend Matrix<R, C> operator+(double lhs, const Matrix& rhs);
    friend Matrix<R, C> operator+(const Matrix& lhs, double rhs);

    friend Matrix<R, C> operator-(const Matrix& lhs, const Matrix& rhs);
    friend Matrix<R, C> operator-(double lhs, const Matrix& rhs);
    friend Matrix<R, C> operator-(const Matrix& lhs, double rhs);

    friend Matrix<R, C> operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix<R, C> operator*(double lhs, const Matrix& rhs);
    friend Matrix<R, C> operator*(const Matrix& lhs, double rhs);

    std::array<double, C>& operator[](std::size_t row);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};

#endif  // DETERMINANT_INHERITANCE_H
