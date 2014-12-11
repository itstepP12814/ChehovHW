#include "Matrix.h"

Matrix::Matrix() {
    lin=col=0;
    m_ptr=NULL;
    //ctor
}
Matrix::Matrix(const Matrix& m1) {
    cout<< "copy constr" <<endl;
    lin=m1.lin;
    col=m1.col;
    m_ptr=new int* [lin];
    for(int i=0; i<lin; ++i) {
        m_ptr[i]=new int [col];//создание собственно самой матрицы
    }
    for(int i=0; i<lin; ++i) {
        for(int j=0; j<col; ++j) {
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
            cout<<m_ptr[i][j]<<"|";
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
        cout<< "\tError matrix configuration\n";
        return trash;
    }
}
Matrix Matrix::operator-(const Matrix& m1) const {
    Matrix trash;
    if(m1.lin==this->lin&&m1.col==this->col) {
        Matrix m2(this->lin, this->col);
        for(int i=0; i<this->lin; ++i) {
            for(int j=0; j<this->col; ++j) {
                m2.m_ptr[i][j]=this->m_ptr[i][j]-m1.m_ptr[i][j];
            }
        }
        return m2;
    } else {
        cout<< "\tError matrix configuration\n";
        return trash;
    }
}
Matrix Matrix::operator*(const Matrix& m1) const {
    Matrix trash;
    if(m1.lin==this->lin&&m1.col==this->col) {
        Matrix m2(this->lin, this->col);
        for(int i=0; i<this->lin; ++i) {
            for(int j=0; j<this->col; ++j) {
                m2.m_ptr[i][j]=this->m_ptr[i][j]*m1.m_ptr[i][j];
            }
        }
        return m2;
    } else {
        cout<< "\tError matrix configuration\n";
        return trash;
    }
}
void Matrix::operator=(const Matrix& m1) {
    cout<< "operator=" <<endl;
    if(m1.lin==this->lin&&m1.col==this->col) {
        lin=m1.lin;
        col=m1.col;
        resize(lin, lin, col, m_ptr);
        for(int i=0 ; i<lin; ++i) {
            for(int j=0; j<col; ++j) {
                m_ptr[i][j]=m1.m_ptr[i][j];
            }
        }
    } else {
        cout<< "error configuration in operator =" <<endl;
    }
}
void Matrix::transpMatrix() {
    if(m_ptr!=NULL) {
        int temp;
        Matrix temp_m(*this);//cоздание временной копии исходной матрицы
        resize(lin, col, lin, m_ptr);//изменяем конфигурацию исходной матрицы на зеркальную
        temp=lin;
        lin=col;
        col=temp;
        //(*this).showMatrix();
        for(int i=0; i<lin; ++i) {
            for(int j=0; j<col; ++j) {
                this->m_ptr[i][j]=temp_m.m_ptr[j][i];
            }
        }
    } else {
        Matrix trash;
        cout<< "error" <<endl;
    }
}
void Matrix:: resize(int prev_lin, int new_lin, int new_col, int** m_ptr) {
    //метод удаляет все данные по указателю, из выделенной области памяти, а затем переразмечает область памяти
    //адресуясь все к тому же указателю, копия которого была передана в качестве аргумента
    //грубо говоря мы меняем конфигурацию оригинальной матрицы переданной нам по указателю, при этом в ячейках будет лежать мусор
    if(m_ptr!=NULL) {
        for(int i=0; i<prev_lin; ++i) {
            delete []m_ptr[i];
        }
        delete []m_ptr;
    }
    //выделение памяти под новую матрицу
    m_ptr=new int* [new_lin];
    //создание новой матрицы
    for(int i=0; i<new_lin; ++i) {
        m_ptr[i]=new int [new_col];
    }
}
int Matrix::getElement (int l, int c)const {
    return m_ptr[l][c];
}
void Matrix::setElement(int l, int c, int value) {
    m_ptr[l][c]=value;
}
