#include "header.h"
void display(int **pArr, int row, int col)
{
    int i, j;
    for(i=0; i<row; ++i)
    {
        for(j=0; j<col; ++j)
        {
            cout<<pArr[i][j];
        }
        cout<<"\n";
    }
}
