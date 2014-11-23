#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
int main1()
{
	//выделение динамической памяти в обычном си
	int n;
	scanf("%d", &n);
	int *array= (int *) malloc(n*sizeof(int));
	if(array==NULL){
	printf("не дала\n");
	return 1;
	}
	freee(array); //очистка динамической памяти
}*/

/*int main(){
//выделение памяти в плюсах
int *array==new int [n];
int *b=realoc(array, новый размер);//перевыделение памяти
}*/

//дана строка, удвоить каждую букву в ней
int main()
{
    char s[]="Talin";
    int len=strlen(s), j=0;
    char *a=(char*) malloc((len*2)*sizeof(char));
    char *b=NULL;
    for(int i=0; i<(len*2); ++i)
    {
        a[j]=s[i];
        a[j+1]=s[i];
        j+=2;
    }
    cout<<a;
    //вставить пробел после каждого знака препинания в строку
return 0;
}
