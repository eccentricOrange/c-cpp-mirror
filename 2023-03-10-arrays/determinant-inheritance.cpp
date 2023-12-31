#include <array>
#include <iostream>

template <std::size_t R, std::size_t C>
class Matrix {
   protected:
    std::array<std::array<double, C>, R> data;

   public:
    /// @brief sets all elements of the matrix to 0
    Matrix() {
        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                data[row][column] = 0;
            }
        }
    }

    /// @brief sets the matrix to the given matrix
    /// @param matrix the input data
    Matrix(std::array<std::array<double, C>, R> matrix) : data(matrix) {}

    /// @brief adds the left hand side matrix to the right hand side matrix, element by element
    /// @param lhs matrix 1
    /// @param rhs matrix 2
    /// @return the sum of the two matrices
    friend Matrix<R, C> operator+(const Matrix& lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator+(double lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs + rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator+(const Matrix& lhs, double rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] + rhs;
            }
        }

        return returnMatrix;
    }

    /// @brief subtracts the right hand side matrix from the left hand side matrix, element by element
    /// @param lhs matrix 1
    /// @param rhs matrix 2
    /// @return the difference of the two matrices
    friend Matrix<R, C> operator-(const Matrix& lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] - rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator-(double lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs - rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator-(const Matrix& lhs, double rhs) {
        Matrix<R, C> returnMatrix;

        for (size_t row = 0; row < R; row++) {
            for (size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] - rhs;
            }
        }

        return returnMatrix;
    }

    /// @brief multiplies the given matrix with the current matrix
    /// @param matrix the input data
    /// @return the product of the two matrices
    /// @warning the number of columns of the first matrix must be equal to the number of rows of the second matrix. I'm unable to figure out a way to check this, since the number of rows and columns are template parameters
    template <std::size_t RHC>
    friend Matrix<R, RHC> operator*(const Matrix<RHC, C>& lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (std::size_t k = 0; k < RHC; k++) {
            for (std::size_t i = 0; i < R; i++) {
                for (std::size_t j = 0; j < C; j++) {
                    returnMatrix[i][j] += lhs.data[i][k] * rhs.data[k][j];
                }
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator*(double lhs, const Matrix& rhs) {
        Matrix<R, C> returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs * rhs.data[row][column];
            }
        }

        return returnMatrix;
    }

    friend Matrix<R, C> operator*(const Matrix& lhs, double rhs) {
        Matrix<R, C> returnMatrix;

        for (std::size_t row = 0; row < R; row++) {
            for (std::size_t column = 0; column < C; column++) {
                returnMatrix.data[row][column] = lhs.data[row][column] * rhs;
            }
        }

        return returnMatrix;
    }

    /// @brief allows you to index a row of the matrix
    /// @param row index of the row
    /// @return the row of the matrix, as an array
    std::array<double, C>& operator[](std::size_t row) {
        return data[row];
    }

    /// @brief return the matrix
    /// @return the `std::array<std::array>` object
    std::array<std::array<double, C>, R> getMatrix() {
        return data;
    }

    /// @brief returns the element at the given row and column
    /// @param row index of the row
    /// @param column index of the column
    int getElement(std::size_t row, std::size_t column) {
        return data[row][column];
    }

    /// @brief sets the matrix to the given matrix
    /// @param matrix the input data
    void setMatrix(std::array<std::array<double, C>, R> data) {
        this->data = data;
    }

    /// @brief sets the element at the given row and column to the given value
    /// @param row index of the row
    /// @param column index of the column
    void setElement(std::size_t row, std::size_t column, double value) {
        data[row][column] = value;
    }

    /// @brief prints the matrix to the given output stream
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
};

/// @brief square matrix, a matrix with the same number of rows and columns
/// @tparam N number of rows and columns
template <std::size_t N>
class SquareMatrix : public Matrix<N, N> {
   public:
    /// @brief reuse the constructor of the base class
    SquareMatrix() : Matrix<N, N>() {}

    /// @brief sets the matrix to the given matrix. reuses the constructor
    /// @param matrix  the input data
    SquareMatrix(std::array<std::array<double, N>, N> data) : Matrix<N, N>(data) {}

    /// @brief extracts the submatrix of the given matrix, ignoring the given row and column
    /// @param ignoreRow row to ignore
    /// @param ignoreColumn column to ignore
    /// @return `SquareMatrix<N - 1>` object, the submatrix
    SquareMatrix<N - 1> subMatrix(std::size_t ignoreRow, std::size_t ignoreColumn) {
        SquareMatrix<N - 1> returnMatrix;

        int subMatrixRow = 0, subMatrixColumn = 0;

        for (std::size_t matrixRow = 0; matrixRow < N; matrixRow++) {
            for (std::size_t matrixColumn = 0; matrixColumn < N; matrixColumn++) {
                if (matrixRow != ignoreRow && matrixColumn != ignoreColumn) {
                    returnMatrix[subMatrixRow][subMatrixColumn++] = this->data[matrixRow][matrixColumn];

                    if (subMatrixColumn == N - 1) {
                        subMatrixColumn = 0;
                        subMatrixRow++;
                    }
                }
            }
        }

        return returnMatrix;
    }

    /// @brief calculates the determinant of the matrix.
    /// see Laplace expansion. https://en.wikipedia.org/wiki/Determinant#Laplace_expansion
    /// @return the determinant of the matrix
    double getDeterminant() {
        double determinant = 0;

        // base case 1
        if constexpr (N == 1) {
            determinant = this->data[0][0];
        }

        // base case 2
        else if constexpr (N == 2) {
            determinant = (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]);
        }

        // recursive case
        else if constexpr (N > 0) {
            int sign = 1;

            for (std::size_t dimension = 0; dimension < N; dimension++) {
                // calculate cofactor and add to determinant
                determinant += sign * this->data[0][dimension] * subMatrix(0, dimension).getDeterminant();
                sign = -sign;
            }
        }

        else {
            throw std::invalid_argument("expected square matrix");
        }

        return determinant;
    }
};

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

    std::cout << "matrixOne "
              << matrixOne;

    std::cout << "matrixTwo "
              << matrixTwo;

    std::cout << "matrixOne + matrixTwo "
              << matrixOne + matrixTwo;

    std::cout << "matrixOne - matrixTwo "
              << matrixOne - matrixTwo;

    std::cout << "matrixOne * matrixTwo "
              << matrixOne * matrixTwo;

    std::cout << "determinant of matrixOne: " << matrixOne.getDeterminant() << '\n';
}
