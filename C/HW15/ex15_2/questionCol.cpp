#include "header.h"
int questionCol(int **p_col, int **p_copy, int row, int col)
{
    int col_num, col_route, col_shift_num ;
    cout<<"\tИсходная матрица\n";
    display(p_col, row, col);
    cout<<"\tВведите номер столбца для сдвига\n";
    cin>>col_num;
    col_num-=1;//отнимаем единицу от номера сдвигаемого столбца, чтобы получить индекс
    cout<<"\tУкажите направление сдвига\n\t1 - влево, 2- вправо\n";
    cin>>col_route;
    cout<<"\tУкажи на сколько столбцов произвести сдвиг\n";
    cin>>col_shift_num;
    switch(col_route)
    {
    case 1:
        shiftColLeft(p_col, p_copy, row, col, col_num, col_shift_num);
        display(p_col, row, col);
        break;
    case 2:
        shiftColRight(p_col,  p_copy, row, col, col_num, col_shift_num);
        display(p_col, row, col);
        break;
    default:
        cout<<"\tОшибка ввода, введите корректную опцию\n";
        break;
    }
    return 0;
}
