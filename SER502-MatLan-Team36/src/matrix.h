#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<double>>& initialData);

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix elementWiseMultiply(const Matrix& other) const;
    Matrix operator/(const Matrix& other) const;
    Matrix operator-() const;

private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif