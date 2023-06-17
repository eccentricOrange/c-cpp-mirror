#include <math.h>

#include <array>
#include <iostream>

template <size_t length>
void printArray(std::array<int, length>& array) {
    printf("\n[%d] array\n", array.size());

    for (size_t counter = 0; counter < array.size(); counter++) {
        printf("%d\t", array.at(counter));

        if ((counter + 1) % 5 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

template <size_t length>
void populateArray(std::array<int, length>& array) {
    int value = 0;

    for (auto&& element : array) {
        element = value++;
    }
}

template <size_t length>
double arrayMagnitude(std::array<int, length>& array) {
    double sum = 0;

    for (auto&& element : array) {
        sum += element;
    }

    return sqrt(sum);
}

template <size_t length>
double arrayMean(std::array<int, length>& array) {
    double sum = 0;

    for (auto&& element : array) {
        sum += element;
    }

    return sum / array.size();
}

template <size_t R, size_t C>
void printMatrix(std::array<std::array<int, C>, R>& matrix) {
    printf("\n[%dx%d] matrix\n", matrix.size(), matrix[0].size());

    for (size_t r = 0; r < matrix.size(); r++) {
        for (size_t c = 0; c < matrix[0].size(); c++) {
            printf("%d\t", matrix.at(r).at(c));
        }

        printf("\n");
    }

    printf("\n");
}

template <size_t R, size_t C>
void populateMatrix(std::array<std::array<int, C>, R>& matrix) {
    int value = 0;

    for (size_t r = 0; r < matrix.size(); r++) {
        for (size_t c = 0; c < matrix[0].size(); c++) {
            matrix.at(r).at(c) = value++;
        }
    }
}

void arrays() {
    std::array<int, 40> array;

    printArray(array);
    populateArray(array);
    printArray(array);
    printf("Magnitude = %f.\n", arrayMagnitude(array));
    printf("Mean = %f.\n", arrayMean(array));
}

void matrices() {
    std::array<std::array<int, 5>, 6> matrix;

    printMatrix(matrix);
    populateMatrix(matrix);
    printMatrix(matrix);
}

int main(int argc, char const* argv[]) {
    arrays();
    return 0;
}
