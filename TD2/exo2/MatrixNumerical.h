//
// Created by Maxime Sanciaume on 11/10/2024.
//

#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

using namespace std;

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    T getDeterminant();

    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}
    MatrixNumerical(const MatrixNumerical<T> &matrix) : MatrixBase<T>(matrix) {}

    MatrixNumerical<T> operator+(const MatrixNumerical<T> &other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T> &other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T> &other) const;
    MatrixNumerical<T> operator*(const T &scalar) const;
};

template<typename T>
T MatrixNumerical<T>::getDeterminant() {
    //TODO : a verifier
    if (this->rows != this->cols) {
        throw invalid_argument("Matrix is not square");
    }
    if (this->rows == 1) {
        return this->data[0][0];
    }
    if (this->rows == 2) {
        return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
    }
    int subi, subj;
    T determinant = 0;
    MatrixNumerical<T> submatrix(this->rows - 1, this->cols - 1);
    for (size_t i = 0; i < this->rows; i++) {
        subi = 0;
        for (size_t ii = 0; ii < this->rows; ii++) {
            if (ii == i) {
                continue;
            }
            subj = 0;
            for (size_t j = 1; j < this->cols; j++) {
                submatrix.data[subi][subj] = this->data[ii][j];
                subj++;
            }
            subi++;
        }
        T subdeterminant = submatrix.getDeterminant();
        if (i % 2 == 0) {
            determinant += this->data[i][0] * subdeterminant;
        } else {
            determinant -= this->data[i][0] * subdeterminant;
        }
    }
    return determinant;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T> &other) const{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T> &other) const{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T> &other) const{
    if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix 1 cols must be equal to matrix 2 rows");
    }
    MatrixNumerical<T> result(this->rows, other.cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for (size_t k = 0; k < this->cols; k++) {
                result.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const T &scalar) const{
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}
#endif //MATRIXNUMERICAL_H
