#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <Eigen/Dense>

class Matrix {
public:
    // Konstruktor dla prostokatnych macierzy
    Matrix(size_t rows, size_t cols);

    // Konstruktor dla macierzy kwadratowych
    Matrix(size_t size);

    // Operator dostępowy do elementow macierzy
    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;

    // Metoda do wypisywania macierzy
    void print() const;

    // Metoda do obliczania wyznacznika (dla macierzy kwadratowej)
    double determinant() const;

    // Operator dodawania macierzy
    Matrix operator+(const Matrix& other) const;

    // Operator odejmowania macierzy
    Matrix operator-(const Matrix& other) const;

    // Operator mnozenia macierzy
    Matrix operator*(const Matrix& other) const;

private:
    Eigen::MatrixXd matrix_;  // Używamy Eigen::MatrixXd do przechowywania macierzy
};

#endif