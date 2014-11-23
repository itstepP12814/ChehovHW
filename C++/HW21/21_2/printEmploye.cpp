#include "prototypes.h"
void printEmploye(Person* p, int num_people) {
    int id;
    cout<<"\tВведите id(порядковый номер) работника\n";
    cin>>id;
    if(id>=0&&id<=num_people) {
        p[id-1].print();
    } else {
        cout<<"\tНеверный id\n";
    }
}
