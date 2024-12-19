#include "Matrix.h"

// Konstruktor dla prostokatnych macierzy
Matrix::Matrix(size_t rows, size_t cols) : matrix_(rows, cols) {}

// Konstruktor dla macierzy kwadratowych
Matrix::Matrix(size_t size) : matrix_(size, size) {}

// Operator dostepowy do elementów macierzy
double& Matrix::operator()(size_t row, size_t col) {
    if (row >= matrix_.rows() || col >= matrix_.cols()) {
        throw std::out_of_range("Index out of range");
    }
    return matrix_(row, col);
}

const double& Matrix::operator()(size_t row, size_t col) const {
    if (row >= matrix_.rows() || col >= matrix_.cols()) {
        throw std::out_of_range("Index out of range");
    }
    return matrix_(row, col);
}

// Metoda do wypisywania macierzy
void Matrix::print() const {
    std::cout << matrix_ << std::endl;
}

// Metoda do obliczania wyznacznika (dla macierzy kwadratowej)
double Matrix::determinant() const {
    if (matrix_.rows() != matrix_.cols()) {
        throw std::invalid_argument("Matrix must be square to compute determinant");
    }
    return matrix_.determinant();
}

// Operator dodawania macierzy
Matrix Matrix::operator+(const Matrix& other) const {
    if (matrix_.rows() != other.matrix_.rows() || matrix_.cols() != other.matrix_.cols()) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result(matrix_.rows(), matrix_.cols());
    result.matrix_ = matrix_ + other.matrix_;
    return result;
}

// Operator odejmowania macierzy
Matrix Matrix::operator-(const Matrix& other) const {
    if (matrix_.rows() != other.matrix_.rows() || matrix_.cols() != other.matrix_.cols()) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    Matrix result(matrix_.rows(), matrix_.cols());
    result.matrix_ = matrix_ - other.matrix_;
    return result;
}

// Operator mnozenia macierzy
Matrix Matrix::operator*(const Matrix& other) const {
    if (matrix_.cols() != other.matrix_.rows()) {
        throw std::invalid_argument("Number of columns in the first matrix must equal the number of rows in the second matrix");
    }
    Matrix result(matrix_.rows(), other.matrix_.cols());
    result.matrix_ = matrix_ * other.matrix_;
    return result;
}