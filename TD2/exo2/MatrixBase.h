//
// Created by Maxime Sanciaume on 11/10/2024.
//

#ifndef MATRIXBASE_H
#define MATRIXBASE_H
#include <vector>
using namespace std;


template<typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase();
    MatrixBase(size_t rows, size_t cols);

    void addElement(size_t rows,size_t cols,T element);
    T getElement(size_t rows,size_t cols);

    vector<T> getRow(size_t row);
    vector<T> getCol(size_t col);

    void display();
};

//partie implementation avec les templates

template<typename T>
MatrixBase<T>::MatrixBase() {
    rows = 1;
    cols = 1;
}

template<typename T>
MatrixBase<T>::MatrixBase(size_t rows_, size_t cols_) {
    rows = rows_;
    cols = cols_;
    data.resize(rows);
    for (size_t i = 0; i < rows; i++) {
        data[i].resize(cols);
    }
}

template<typename T>
void MatrixBase<T>::addElement(size_t rows_, size_t cols_, T element) {
    data[rows_][cols_] = element;
}

template<typename T>
T MatrixBase<T>::getElement(size_t rows_, size_t cols_) {
    return data[rows_][cols_];
}

template<typename T>
vector<T> MatrixBase<T>::getRow(size_t row) {
    return data[row];
}

template<typename T>
vector<T> MatrixBase<T>::getCol(size_t col) {
    vector<T> res;
    for (size_t i = 0; i < rows; i++) {
        res.push_back(data[i][col]);
    }
    return res;
}

template<typename T>
void MatrixBase<T>::display() {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
#endif //MATRIXBASE_H
