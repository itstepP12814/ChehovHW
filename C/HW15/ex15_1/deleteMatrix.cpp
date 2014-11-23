#include "header.h"
void deleteMatrix(int **pArr, int row)
{
    for(int i=0; i<row; ++i)
    {
        delete []pArr[i];
    }
    delete []pArr;
}
