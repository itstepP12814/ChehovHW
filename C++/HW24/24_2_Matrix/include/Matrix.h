#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Matrix {
public:
    Matrix();
    Matrix(const Matrix&);
    Matrix(int l, int c);
    Matrix operator+(const Matrix&)const;
    void operator=(const Matrix&);
    virtual ~Matrix();
    void showMatrix() const;
protected:
    int lin;//количество одномерных массивов
    int col;//количество эл-тов в одном таком массиве
    int** m_ptr;//указатель на массив указателей
};

#endif // MATRIX_H
