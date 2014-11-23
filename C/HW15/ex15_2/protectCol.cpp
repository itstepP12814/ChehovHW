#include "header.h"
int protectCol(int col_route, int num, int col_shift_num)
{
    switch(col_route)
    {
    case 1:
        if(num<col_shift_num) return 1;
        else return 0;
    case 2:
        if(num>col_shift_num) return 1;
        else return 0;
    }
    return 0;
}
