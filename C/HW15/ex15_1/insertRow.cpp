#include "header.h"
/*
Эта функция создает новый массив и заполняет го нулями. Потом на место той строки куда надо было вставить строку
запишутся пятерки
*/
void insertRow(int **pArr, int row, int col, int insert_row)
{
    int i, j;
    for(i=row-1; i<row; ++i)
    {
        pArr[i]=new int [col];
        for(j=0; j<col; ++j)
        {
            pArr[i][j]=0;
        }
    }
    for(i=insert_row-1; i<insert_row; ++i)
    {
        for(j=0; j<col; j++)
        {
            pArr[i][j]=insert_row;
        }
    }
}
