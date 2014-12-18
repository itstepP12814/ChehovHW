#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;
class Client {
public:
    Client();
    Client(int, int);
    virtual ~Client();
    friend class Printer;
protected:
    int prior;
    int pages;
};

#endif // CLIENT_H
