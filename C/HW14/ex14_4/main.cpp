#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
/*4. Пользователь вводит отдельно строку и символ, необходимо показать на
экран номера по порядку всех совпадений (нумерация с единицы).*/
int main()
{
    char *string=new char[128];
    char f;
    printf("\tСтрока ввода\n");
    gets(string);
    printf("\tВведи искомый символ\n");
    f=getchar();
    for(int i=0; i<strlen(string); ++i)
    {
	if(*(string+i)==f) printf("\t%d", i+1);
    }
    delete []string;
    return 0;
}
