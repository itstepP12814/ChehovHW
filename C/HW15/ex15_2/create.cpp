#include "header.h"
int **create(int row, int col, int dif)
{
    int i, j;
    int **pArr=new int *[col];
    for(i=0; i<row; ++i)
    {
        pArr[i]=new int[col];
    }
    for(i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            switch(dif)
            {
            case 1:
                pArr[i][j]=i+1;
                break;
            case 2:
                pArr[i][j]=j+1;
                break;
            default :
                break;
            }
        }
    }
    return pArr;
}
