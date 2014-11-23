#include "header.h"
void sgets(char* name) {
    FILE* p_file=fopen(name, "r");//указатель на открытый файл
    if(p_file!=NULL) {
        char str[SIZE], *p;//буферная строка и просто чаровый указатель
        int empty=0, fill=0;//счетчики пустых и заполненных строк
        while(!feof(p_file)) {
            fgets(str, SIZE, p_file);
            p=strchr(str, '\n');//получения указателя на символ новой строки
            if(*p==str[0]) empty++;//если символ новой  первый в строке, значит строка пустая, делаем инкремет к счетчику
            else fill++;
        }
        cout<<"Заполненных строк: "<<fill-1<<endl;
        cout<<"Пустых строк: "<<empty+1<<endl;
        fcloseall();
    } else cout<<"\tФайл не найден!\n";
}
