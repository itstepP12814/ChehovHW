#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
using namespace std;

class counter {
public:
    counter(int, int);
    ~counter();
    void increment() {
        if(count>=min&&count<=max) ++count;
        if(count==max+1) count=min;
    }
    int show() {
        return count;
    }
private:
    int max;//макс значение, по достижении его счетчик будет сбрасываться на минимальное значение
    int min;//мин значение
    int count;//переменная счетчика
};

#endif // COUNTER_H
