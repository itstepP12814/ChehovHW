#include "header.h"
void selection(int **p, int row, int col)
{
    //p-указатель на исходную матрицу
    int choice=0, insert_row, insert_col, **p_copy;
    while(choice==0)
    {
        cout<<"\tДобавить строку - нажми 1, столбец - нажми 2, выход - 3\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\tУкажите позицию для добавления строки\n";
            cin>>insert_row;
            ++row;
            insertRow(p, row, col, insert_row);
            display(p, row, col);
            cout<<"\tДобавить еще что нибудь?\n";
            selection(p, row, col);
            break;
        case 2:
            cout<<"\tУкажите позицию для добавления столбца\n";
            cin>>insert_col;
            ++col;//говорим прграмме, что хотим увидеть на один столбец больше
            p_copy=create(row, col);//создаем новую матрицу. на один столбец больше предыдущей, указатель на нее пишем в p_copy;
            copyMatrix(p, p_copy, row, col);//переписываем предыдущую матрицу в новую большую на один столбец
            insertCol(p_copy, row, col, insert_col);//вставляем в нужный столбец номер вставляемого столбца
            display(p_copy, row, col);
            cout<<"\tДобавить еще что нибудь?\n";
            selection(p_copy, row, col);
            break;
        case 3:
            break;
        default:
            cout<<"\tОшибка ввода! ВВедите верное значение параметра\n";
            choice=0;
            break;
        }
    }
    deleteMatrix(p, row);//удаляем оригинальную матрицу
    deleteMatrix(p_copy, row);//удаляем копию
    //я не совсем уверен насчет удаления, работает ли оно корректно...но проверить не знаю как*/
}
