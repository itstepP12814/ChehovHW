#ifndef PERSON_H
#define PERSON_H
enum sex {female, male};

class Person {
public:
    Person();
    ~Person();
    void inName();
    void inSurname();
    void inAge();
    void inSex();
    void inNumber();
    void print();
protected:
    char name[64];
    char surname[64];
    int age;
    sex sx;
    char number[64];
};
#endif // PERSON_H
