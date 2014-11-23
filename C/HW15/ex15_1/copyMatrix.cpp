#include "header.h"
void copyMatrix(int **pArr, int **p_copy,int row,  int col)
{
    int i,j;
    for(i=0; i<row; ++i)
    {
        for(j=0; j<col-1; ++j) /*тут мы уже изменили количество столбцов, потому при перезаписи при обращении к оригинальной матрице
        указываем на один столбец меньше*/
        {
            p_copy[i][j]=pArr[i][j];
        }
    }
}
