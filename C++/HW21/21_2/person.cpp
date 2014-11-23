#include "person.h"
#include <iostream>
using namespace std;

Person::Person() {
    //cout<<"\tconstructor\n";
    //ctor
}

Person::~Person() {
    //cout<<"\tdestructor\n";
    //dtor
}

void Person::inName() {
    cout<<"\tВведите имя\n";
    cin>>name;
}
void Person::inSurname() {
    cout<<"\tВведите фамилию\n";
    cin>>surname;
}
void Person::inAge() {
    cout<<"\tВведите возраст\n";
    cin>>age;
}
void Person::inNumber() {
    cout<<"\tВведите номер телефона\n";
    cin>>number;
}
void Person::inSex() {
    char s;
    cout<<"\tВведите пол m/f\n";
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
//аналогично объявлению обычного массива функций
void Person::print() {
    char* fields[]= {"\tИмя ", "\tФамилия ", "\tВозраст ", "\tПол ", "\tНомер телефона "};
    char* s[]= {"женский", "мужской"};
    int i=0;
    cout<<fields[i]<<name<<endl;
    cout<<fields[++i]<<surname<<endl;
    cout<<fields[++i]<<age<<endl;
    cout<<fields[++i]<<s[sx]<<endl;
    cout<<fields[++i]<<number<<endl<<endl;
}
