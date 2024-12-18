#include "MatrixFactory.h"

// Tworzenie prostokątnych macierzy
std::unique_ptr<Matrix> MatrixFactory::createMatrix(size_t rows, size_t cols) {
    return std::make_unique<Matrix>(rows, cols);
}

// Tworzenie kwadratowych macierzy
std::unique_ptr<Matrix> MatrixFactory::createSquareMatrix(size_t size) {
    return std::make_unique<Matrix>(size);
}