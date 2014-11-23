#include "header.h"
void insertCol(int **p_copy, int row, int col, int insert_col)
{
    int i, j;
    for(i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            if(j==insert_col-1)//отнимаем единицу т.к люди считают столбцы с 1 а не с 0
            {
                p_copy[i][j]=insert_col;
            }
        }
    }
}
