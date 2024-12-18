#include "MatrixFactory.h"
#include <iostream>

int main() {
    try {
        // Tworzenie macierzy przez fabrykę
        auto matrix1 = MatrixFactory::createMatrix(2, 3);  // 2x3
        auto matrix2 = MatrixFactory::createMatrix(2, 3);  // 2x3

        // Ustawianie wartości w matrix1
        (*matrix1)(0, 0) = 1; (*matrix1)(0, 1) = 2; (*matrix1)(0, 2) = 3;
        (*matrix1)(1, 0) = 4; (*matrix1)(1, 1) = 5; (*matrix1)(1, 2) = 6;

        // Ustawianie wartości w matrix2
        (*matrix2)(0, 0) = 7; (*matrix2)(0, 1) = 8; (*matrix2)(0, 2) = 9;
        (*matrix2)(1, 0) = 10; (*matrix2)(1, 1) = 11; (*matrix2)(1, 2) = 12;

        std::cout << "Matrix 1:\n";
        matrix1->print();

        std::cout << "Matrix 2:\n";
        matrix2->print();

        // Dodawanie macierzy
        auto result = *matrix1 + *matrix2;
        std::cout << "Result of addition:\n";
        result.print();

        // Tworzenie macierzy kwadratowej
        auto squareMatrix = MatrixFactory::createSquareMatrix(3);

        // Ustawianie wartości w macierzy kwadratowej
        (*squareMatrix)(0, 0) = 6; (*squareMatrix)(0, 1) = 1; (*squareMatrix)(0, 2) = 1;
        (*squareMatrix)(1, 0) = 4; (*squareMatrix)(1, 1) = 2; (*squareMatrix)(1, 2) = 5;
        (*squareMatrix)(2, 0) = 2; (*squareMatrix)(2, 1) = 8; (*squareMatrix)(2, 2) = 7;

        std::cout << "Square Matrix:\n";
        squareMatrix->print();

        // Obliczanie wyznacznika
        std::cout << "Determinant of square matrix: " << squareMatrix->determinant() << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}