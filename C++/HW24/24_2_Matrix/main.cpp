#include <iostream>
#include "Matrix.h"
using namespace std;
/*Создать класс для работы с матрицами.
Предусмотреть, как минимум, функции для сложения матриц, умножения матриц, транспонирования матриц,
присваивания матриц друг другу, установка и получение произвольного элемента матрицы.
Необходимо перегрузить соответствующие операторы.*/
int main() {
    cout << "matrix A" <<endl;
    Matrix A(5,5);
    A.showMatrix();
    cout << "matrix A" <<endl;
    Matrix B(5,5);
    B.showMatrix();
    Matrix C(5,5);
    cout<< "+" <<endl;
    C=A+B;
    C.showMatrix();
    cout<< "matrix C=A" <<endl;
    C=A;
    C.showMatrix();
    cout<< "-" <<endl;//т.к матрицы созданы в одну и ту же секунду, при их вычитании должна получиться матрица с нулями
    C=A-B;
    C.showMatrix();
    cout << "*" <<endl;
    C=A*B;
    C.showMatrix();
    cout<< "get element (1,2)" <<endl;
    cout<<C.getElement(1,2)<<endl;
    cout<< "set element (1,2, value=25)" <<endl;
    C.setElement(1,2, 25);
    cout<<C.getElement(1,2)<<endl;
    cout<< "transponir A" <<endl;
    A.transpMatrix();
    A.showMatrix();
    return 0;
}
