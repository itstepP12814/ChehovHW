#include "Matrix.h"

Matrix::Matrix() {
    lin=col=0;
    m_ptr=NULL;
    //ctor
}
Matrix::Matrix(const Matrix& m1) {
    cout<< "copy constr"<<endl;
    lin=m1.lin;
    col=m1.col;
    m_ptr=new int* [lin];
     for(int i=0; i<lin; ++i) {
        m_ptr[i]=new int [col];//создание собственно самой матрицы
    }
    for(int i=0; i<lin; ++i){
        for(int j=0; j<col; ++j){
            m_ptr[i][j]=m1.m_ptr[i][j];
        }
    }
}
Matrix::Matrix(int l, int c) {
    srand(time(NULL));
    lin=l;//кол-во массивов
    col=c;//кол-во эл-тов в 1 массиве
    m_ptr = new int* [lin]; //создание массива указателей, на массивы интов
    for(int i=0; i<lin; ++i) {
        m_ptr[i]=new int [col];//создание собственно самой матрицы
    }

    for(int i=0; i<lin; ++i) {
        for(int j=0; j<col; ++j) {
            m_ptr[i][j]=rand()%10;
        }
    }
}

Matrix::~Matrix() {
    //dtor
}
void Matrix::showMatrix()const {
    for(int i=0; i<lin; ++i) {
        for(int j=0; j<col; ++j) {
            cout<<m_ptr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
Matrix Matrix::operator+(const Matrix& m1) const {
    //функция складывает значения из двух матриц с одинаковыми конфигурациями
    Matrix trash;
    if(m1.lin==this->lin&&m1.col==this->col) {
        Matrix m2(this->lin, this->col);
        for(int i=0; i<this->lin; ++i) {
            for(int j=0; j<this->col; ++j) {
                m2.m_ptr[i][j]=this->m_ptr[i][j]+m1.m_ptr[i][j];
            }
        }
        return m2;
    } else {
        cout<< "\tError size of matrix\n";
        return trash;
    }
}
void Matrix::operator=(const Matrix& m1) {
    cout<< "operator=" <<endl;
    //Удаление предыдущей матрицы
    for(int i=0; i<lin; ++i) {
        delete m_ptr[i];
    }
    delete []m_ptr;
    //переписка данных
    lin=m1.lin;
    col=m1.col;
    //выделение памяти под новую
    m_ptr=new int* [lin];
    //создание новой матрицы
    for(int i=0; i<lin; ++i) {
        m_ptr[i]=new int [col];
    }
    for(int i=0 ; i<lin; ++i) {
        for(int j=0; j<col; ++j) {
            m_ptr[i][j]=m1.m_ptr[i][j];
        }
    }
}
