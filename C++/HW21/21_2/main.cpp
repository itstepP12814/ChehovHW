#include "prototypes.h"
/*1. Разработать класс Person, который содержит соответствующие члены для
хранения:
     имени,
     возраста,
     пола и
     телефонного номера.
Напишите функции-члены, которые смогут изменять эти члены данных
индивидуально. Напишите функцию-член Person::Print(), которая выводит
отформатированные данные о человеке.*/
int main() {
    int num_people;//количество работников
    char opt[10];//выбор опции
    int o;//переменная для свича
    cout<<"\tВведите количество работников\n";
    cin>>num_people;
    Person* p=new Person[num_people];
    inputAllData(p, num_people);
    while(1) {
        cout<<"\t1 - изменить записи в базе\n\t2 - показать инфо о работнике\n\t3 - показать онфо обо всех работниках\n";
        scanf("%s", opt);
        o=atoi(opt);
        switch(o) {
        case 1:
            editEmploye(p, num_people);
            break;
        case 2:
            printEmploye(p, num_people);
            break;
        case 3:
            for(int i=0; i<num_people; ++i) {
                p[i].print();
            }
            break;
        default:
            cout<<"\tНеверная опция\n";
            break;
        }
        cout<<"\tПродолжить работу? y/n\n";
        scanf("%s", opt);
        if( strcmp("y", opt)!=0 && strcmp("Y", opt)!=0 ) break;
    }
    delete []p;
    return 0;
}
