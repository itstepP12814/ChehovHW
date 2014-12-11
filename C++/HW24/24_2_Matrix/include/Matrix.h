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
    virtual ~Matrix();
    Matrix operator+(const Matrix&)const;
    Matrix operator-(const Matrix&)const;
    Matrix operator*(const Matrix&)const;
    int getElement(int, int)const;
    void transpMatrix();
    void resize(int, int, int, int**);
    void operator=(const Matrix&);
    void setElement(int, int, int);
    void showMatrix() const;
protected:
    int lin;//количество одномерных массивов
    int col;//количество эл-тов в одном таком массиве
    int** m_ptr;//указатель на массив указателей
};

#endif // MATRIX_H
