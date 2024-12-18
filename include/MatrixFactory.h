#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "Matrix.h"
#include <memory>

class MatrixFactory {
public:
    // Tworzenie prostokątnych macierzy
    static std::unique_ptr<Matrix> createMatrix(size_t rows, size_t cols);

    // Tworzenie kwadratowych macierzy
    static std::unique_ptr<Matrix> createSquareMatrix(size_t size);
};

#endif