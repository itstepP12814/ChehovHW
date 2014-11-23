#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
enum sex {female, male};
class student {
public:
    student();
    ~student();

    void enterAge() {
        cin>>age;
    }
    void enterHeight() {
        cin>>height;
    }
    void enterWeight() {
        cin>>weight;
    }
    void enterSex() {
        char s;
        cin>>s;
        switch(s) {
        case 'f':
            sx=female;
            break;
        case 'm':
            sx=male;
            break;
        default:
            break;
        }
    }
    void showStudent(int id) {
        char* str[]= {" Студент № ", " Пол ", " Возраст ", " Рост ", " Вес "};
        char* s[]= {"женский", "мужской"};
        cout<<str[0]<<id+1<<endl;//номер студента, он же айди, передается в качестве параметра методом showGroup
        cout<<str[1]<<s[sx]<<endl;
        cout<<str[2]<<age<<endl;
        cout<<str[3]<<height<<endl;
        cout<<str[4]<<weight<<endl;
    }
private:
    int height;
    int weight;
    int age;
    sex sx;
};

#endif // STUDENT_H
