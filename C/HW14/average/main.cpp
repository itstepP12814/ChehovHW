#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*требовалось реализовать подсчет среднего при вводе строки из двух чисел. Кажется у меня не совсем то что требовалось, но надеюсь похоже =)*/
using namespace std;
int main(int m, char *string[])
{
    double p;
    double summ=0;
    for(int i=1; i<m; ++i){
    p=atof(*(string+i));
    summ=summ+p;
    }
    printf("Среднее %f\n", summ/(m-1));
    return 0;
}
