#ifndef PRINTER_H
#define PRINTER_H
#include "Client.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
struct user {
    int id;
    int time;
};
class Printer {
public:
    Printer();
    Printer(int);
    virtual ~Printer();
    void setQueue(const Client);
    void resize();//Метод переразмечающий память
    void print()const;
    void insert(const Client);
protected:
    Client* queue;//данимически выделенная очередь под массив объектов-клиентов
    user* users;//массив со временем необходимым на обработку каждого клиента очереди
    int count;//количество клиентов
    int max;//максимальное количество клиентов
};

#endif // PRINTER_H
