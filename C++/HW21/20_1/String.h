#ifndef STRING_H
#define STRING_H
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
class String {
public:
    String();//конструктор по умолчания
    String(int);//конктруктор для создания строки с заданным размером
    String(const String &source);//конструктор копирования строки
    void inToStream();//метод для ввода строки
    void printToStream(ostream &str);//конструктор записи строки в поток
    ~String();//деструктор
protected:
    char* s;
    size_t lenght;//тип для хранения длины строки
};

#endif // STRING_H
