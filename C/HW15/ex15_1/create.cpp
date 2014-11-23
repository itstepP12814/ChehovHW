#include "header.h"
//исходная матрица по умолчанию будет заполнена нулями
int  **create( int row, int col)
{
    int i, j;
    int **pArr=new int *[row];
    for(i=0; i<row; ++i)
    {
        pArr[i]=new int[col];
    }
    for(i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            pArr[i][j]=0;
        }
    }
    return pArr;
}

