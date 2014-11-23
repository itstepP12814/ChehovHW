#include "prototypes.h"
void editEmploye(Person* p, int num_people) {
    char opt[10];
    int id, o;
    while(1) {
        cout<<"\tВведите id(порядковый номер) работника\n";
        cin>>id;
        if(id>=0&&id<=num_people) {
            cout<<"\tВыберите опцию\n";
            cout<<"\t1 - редактировать имя\n\t2 - редактировать фамилию\n\t3 - редактировать возраст\n";
            cout<<"\t4 - редактировать пол\n\t5 - редактировать телефонный номер\n";
            scanf("%s", opt);
            o=atoi(opt);
            switch(o) {
            case 1:
                p[id-1].inName();
                break;
            case 2:
                p[id-1].inSurname();
                break;
            case 3:
                p[id-1].inAge();
                break;
            case 4:
                p[id-1].inSex();
                break;
            case 5:
                p[id-1].inNumber();
                break;
            default:
                break;
            }
            cout<<"\tПродолжить редактирование? y/n\n";
            scanf("%s", opt);
            if(strcmp("y", opt)!=0 && strcmp("Y", opt)!=0 ) break;
        } else {
            cout<<"\tНеверный id\n";
        }
    }
}
