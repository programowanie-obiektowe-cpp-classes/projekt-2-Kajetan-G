#include "MatrixFactory.h"
#include <iostream>

int main() {
    try {
        // Tworzenie macierzy przez fabryke
        auto matrix1 = MatrixFactory::createMatrix(2, 3);  // 2x3
        auto matrix2 = MatrixFactory::createMatrix(2, 3);  // 2x3

        // Ustawianie wartosci w matrix1
        (*matrix1)(0, 0) = 1; (*matrix1)(0, 1) = 2; (*matrix1)(0, 2) = 3;
        (*matrix1)(1, 0) = 4; (*matrix1)(1, 1) = 5; (*matrix1)(1, 2) = 6;

        // Ustawianie wartosci w matrix2
        (*matrix2)(0, 0) = 7; (*matrix2)(0, 1) = 8; (*matrix2)(0, 2) = 9;
        (*matrix2)(1, 0) = 10; (*matrix2)(1, 1) = 11; (*matrix2)(1, 2) = 12;

        std::cout << "Matrix 1:\n";
        matrix1->print();

        std::cout << "Matrix 2:\n";
        matrix2->print();

        // Dodawanie macierzy
        auto additionResult = *matrix1 + *matrix2;
        std::cout << "Result of addition:\n";
        additionResult.print();

        // Odejmowanie macierzy
        auto subtractionResult = *matrix1 - *matrix2;
        std::cout << "Result of subtraction:\n";
        subtractionResult.print();

        // Tworzenie macierzy do mnozenia
        auto matrix3 = MatrixFactory::createMatrix(3, 2);  // 3x2

        (*matrix3)(0, 0) = 1; (*matrix3)(0, 1) = 2;
        (*matrix3)(1, 0) = 3; (*matrix3)(1, 1) = 4;
        (*matrix3)(2, 0) = 5; (*matrix3)(2, 1) = 6;

        std::cout << "Matrix 3:\n";
        matrix3->print();

        // Mnozenie macierzy
        auto multiplicationResult = *matrix1 * *matrix3;
        std::cout << "Result of multiplication:\n";
        multiplicationResult.print();

        // Tworzenie macierzy kwadratowej
        auto squareMatrix = MatrixFactory::createSquareMatrix(3);

        // Ustawianie wartosci w macierzy kwadratowej
        (*squareMatrix)(0, 0) = 6; (*squareMatrix)(0, 1) = 1; (*squareMatrix)(0, 2) = 1;
        (*squareMatrix)(1, 0) = 4; (*squareMatrix)(1, 1) = -2; (*squareMatrix)(1, 2) = 5;
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