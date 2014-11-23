#include "header.h"
int questionRow(int **p_rows, int **p_copy, int row, int col)
{
    int row_num, row_route, row_shift_num;
    cout<<"\tИсходная матрица\n";
    display(p_rows, row, col);
    cout<<"\tВведите номер строки, котрую будем двигать\n";
    cin>>row_num;
    row_num-=1;//т.к мы не машины, исчитаем с 1, то мы отнимаем от номера строчки единицу
    cout<<"\tУкажи направление для сдвига\n\t1 - вверх, 2 - вниз\n";
    cin>>row_route;
    cout<<"\tУкажите на сколько строк произвести сдвиг\n";
    cin>>row_shift_num;
    switch(row_route)
    {
    case 1:
        shiftRowUp(p_rows, p_copy, row, col, row_num, row_shift_num);
        display(p_rows, row, col);
        break;
    case 2:
        shiftRowDown(p_rows, p_copy, row, col, row_num, row_shift_num);
        display(p_rows, row, col);
        break;
    default:
        cout<<"\tОшибка ввода, введите корректную опцию\n";
        break;
    }
    return 0;
}
