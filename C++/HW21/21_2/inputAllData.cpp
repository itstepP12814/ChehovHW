#include "prototypes.h"
void inputAllData(Person* p, int num_people) {
    for(int i=0; i<num_people; ++i) {
        p[i].inName();
        p[i].inSurname();
        p[i].inAge();
        p[i].inSex();
        p[i].inNumber();
    }
}
