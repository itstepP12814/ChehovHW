#include "main.h"
#include "date.h"
void diff() {
    Date A, B;
    int diff;
    char str[15]= {};
    cout<<"\tВедите дату №1\n";
    cin>>str;
    A.enterDate(str);
    cout<<"\tВведите дату №2\n";
    cin>>str;
    B.enterDate(str);
    diff=A-B;
    cout<<"\tразница составила"<<diff<<" дня"<<endl;
}
