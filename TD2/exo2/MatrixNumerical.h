//
// Created by Maxime Sanciaume on 11/10/2024.
//

#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    T getDeterminant();

    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}
    MatrixNumerical(const MatrixNumerical<T> &matrix) : MatrixBase<T>(matrix) {}

    friend MatrixNumerical<T> operator+(const MatrixNumerical<T> &matrix1, const MatrixNumerical<T> &matrix2);
    friend MatrixNumerical<T> operator-(const MatrixNumerical<T> &matrix1, const MatrixNumerical<T> &matrix2);
    friend MatrixNumerical<T> operator*(const MatrixNumerical<T> &matrix1, const MatrixNumerical<T> &matrix2);
    friend MatrixNumerical<T> operator*(const MatrixNumerical<T> &matrix, const T &scalar);
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

#endif //MATRIXNUMERICAL_H
