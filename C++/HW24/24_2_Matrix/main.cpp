#include <iostream>
#include "Matrix.h"
using namespace std;
/*Создать класс для работы с матрицами.
Предусмотреть, как минимум, функции для сложения матриц, умножения матриц, транспонирования матриц,
присваивания матриц друг другу, установка и получение произвольного элемента матрицы.
Необходимо перегрузить соответствующие операторы.*/
int main() {
    Matrix A(5,5);
    A.showMatrix();
    Matrix B(5,5);
    B.showMatrix();
    Matrix C(5,5);
    C=A+B;
    C.showMatrix();
    C=A;
    C.showMatrix();
    Matrix D(C);
    D.showMatrix();
    return 0;
}
