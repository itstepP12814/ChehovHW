#include "main.h"
#include "date.h"
void summ() {
    char str[15]= {}; //строка инициализаровання нулями
    int number_of_days;
    Date A;
    cout<<"\tВедите дату\n";
    cin>>str;
    A.enterDate(str);
    cout<<"\tВведите количество дней, которые необходимо прибавить\n";
    cin>>number_of_days;
    A+=number_of_days;
    A.getDate();
}
