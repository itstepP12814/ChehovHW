#ifndef TIME_H
#define TIME_H
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
struct mytm {
    int hour;
    int min;
    int sec;
};
class MyTime {
public:
    MyTime();
    MyTime(char*);
    MyTime(const MyTime&);
    virtual ~MyTime();
    void getTimeEu() const;
    void getTimeUs() const;
    void convert(char*);
    void setTime(char*);
    void operator=(const MyTime&);
    MyTime operator+(const MyTime&) const;
    MyTime operator-(const MyTime&) const;
    int operator==(const MyTime&) const;
protected:
    time_t t;
    struct tm* aTm;
    struct mytm* mytime;
};

#endif // TIME_H
