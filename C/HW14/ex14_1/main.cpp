#include <stdio.h>
#include <string.h>
using namespace std;
/*
1. Пользователь вводит строку с клавиатуры в фиксированный массив.
Необходимо проверить, сколько элементов массива теперь занято и сколько
свободно.
*/
int main()
{
	int len=100;
	char *string=new char[len];
	printf("\tInput string\n");
	gets(string);
	printf("\tзанято %d свободно %d", strlen(string), len-strlen(string));
	delete []string;
    return 0;
}
