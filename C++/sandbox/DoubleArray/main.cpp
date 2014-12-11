#include <iostream>

using namespace std;
//пример создания и удаления двумерного массива
int main() {
    int size=5;//величина массива указателей
    int size_of_integer=7;//величина массивов с числами
    int** p; //указатель на массив указателей
    p=new int* [size];//выделение памяти под массив указателей
    for(int i=0; i<size; ++i) {
        p[i]=new int[size_of_integer];//запись в каждый указатель из массива указателей, адреса нового массива интов
    }
    //заполнение массива
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size_of_integer; ++j) {
            p[i][j]=5;
        }
    }
    //вывод массива
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size_of_integer; ++j) {
            cout << p[i][j];
        }
        cout<<endl;
    }
    //удаление массива
    for(int i=0; i<size; ++i) {
        //Удаление памяти с интами, на который ссылается каждый указатель из массива
        delete []p[i];
    }
    delete []p;//Удаление указателя на массив указателей

    return 0;
}
