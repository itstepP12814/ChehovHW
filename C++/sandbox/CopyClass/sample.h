#ifndef SAMPLE_H
#define SAMPLE_H
#include <iostream>
using namespace std;

class sample {
public:
    sample(int, int);
    ~sample();
    void print();
private:
    int a, b;
};
#endif // SAMPLE_H
