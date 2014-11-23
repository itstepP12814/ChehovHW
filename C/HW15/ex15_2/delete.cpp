#include "header.h"
void del(int **pArr_row, int **pArr_col, int **pArr_copy, int row)
{
    int i;
    for(i=0; i<row; ++i)
    {
        delete []pArr_row[i];
        delete []pArr_col[i];
        delete []pArr_copy[i];
    }
    delete []pArr_row;
    delete []pArr_col;
    delete []pArr_copy;
}
