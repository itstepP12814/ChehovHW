#include "header.h"
void gets()
{
    char filename[]="sample";
    FILE* input = fopen(filename,"r"); //файл находится в папке main (папка main находится в папке с проектом)
    //  параметр "r", то есть reed - позволит нам только считать информацию.
    FILE* output=fopen(strcat(filename, "_edit"), "wb");//открываем файл на запись в банорном режиме
    if(input!=NULL)
    {
        //функция возвращает нам ненулевой указатель,значит файл не может открыться.Либо путь не тот.
        char str[64];       //создаём строку(string) размером 64.
        fgets(str,64,input);   //записываем в str первую строку.
        while(!feof(input))    //пока не конец файла input ,мы исполняем цикл.
        {
            PARS_STRING(str);
            PARS_CHARACTERS(str);
            cout<<str;        //выводим на экран первую строку.
            fputs(str, output);//ложим ее в новый файл
            fgets(str,64,input); //записываем вторую.
        }
        fcloseall();         //закрываем все открытые (в нашем случае один) файлы.
    }
    else
    {
        cout<<"Ошибка в открытии файла"<<endl;
    }
}

