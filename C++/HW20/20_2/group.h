#ifndef GROUP_H
#define GROUP_H
#include "student.h"

class group {
public:
    group(int);
    ~group();

    student* p; //указатель на объект класса студент

    void showGroup() {
        for(int i=0; i<number_of_students; ++i) {
            p[i].showStudent(i);
        }
    }
private:
    int number_of_students;
};

#endif // GROUP_H
