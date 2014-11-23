#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int figure();
int main()
{
    figure();
    return 0;
}
int figure()
{
    const int n=5;
    const int m=n;
    int array[n][m];
    srand(time(NULL));
//заполняем матрицу n*m
    cout<<"\t\tМатрица"<<endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            array[i][j]=rand()%100;//добавив +1 диапазон будет от 1 до 100, иначе от 0 до 99;
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
//фигура А
    int start=0;
    int str=0;
    int stlb=0;
    int max=array[0][0];//предполагаем, что макс находиться в 0 строке и 0 столбце
    for(int i=0; i<n; ++i)
    {
        for(int j=start; j<m; ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        start++;
    }
    cout<<"фигура А максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
//Фигура Б
    start=0;
    max=array[0][0];
    str=0;
    stlb=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<start; ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        start++;
    }
    cout<<"фигура Б максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
//фигура В
    start=0;
    max=array[0][0];
    str=0;
    stlb=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=start; j<(m-start); ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        start++;
    }
    cout<<"фигура В максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
//фигура Г
    int half=n/2; //начинаем перебирать числа со срединной строки матрицы, нам надо разделить наш квадрат на пополам и начать цикл
    start=m/2; //тк старт это интовая целочисленная переменная при делении 5/2 она округлится до 2, тут мы начинаем цикл сосрединного столбца
    max=array[half][start];//предполагаем, что макс находиться в средней строке и среднем столбце
    str=half;
    stlb=start;
    for(int i=half; i<n; ++i)
    {
        for(int j=start; j<(m-start); ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        start--;
    }
    cout<<"фигура Г максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
//Фигура Д
    start=0;
    max=array[0][0];
    int str1, stlb1;
    str1=0;
    stlb1=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=start; j<(m-start); ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str1=i;
                stlb1=j;
            }
        }
        start++;
    }
    int max1=max;
    half=n/2; //начинаем перебирать числа со срединной строки матрицы, нам надо разделить наш квадрат на пополам и начать цикл
    start=m/2; //тк старт это интовая целочисленная переменная при делении 5/2 она округлится до 2, тут мы начинаем цикл сосрединного столбца
    max=array[half][start];//предполагаем, что макс находиться в средней строке и среднем столбце
    int str2, stlb2;
    str2=0;
    stlb2=0;
    for(int i=half; i<n; ++i)
    {
        for(int j=start; j<(m-start); ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str2=i;
                stlb2=j;
            }
        }
        start--;
    }
    int max2=max;
    if(max1>max2)
    {
        cout<<"фигура Д максимальный элемент со значением "<<max1<<" находится в "<<str1<<" строке "<<stlb1<<" столбце"<<endl;
    }
    else
    {
        if(max1<max2)
        {
            cout<<"фигура Д максимальный элемент со значением "<<max2<<" находится в "<<str2<<" строке "<<stlb2<<" столбце"<<endl;
        }
        else
        {
            if(max1==max2)
            {
                cout<<"фигура Д максимальный элемент со значением "<<max2<<" находится в "<<str2<<" строке "<<stlb2<<" столбце"<<endl;
            }
        }
    }
//фигура Е
    max1=array[0][0];
    max2=array[0][m-1];
    str1=0;
    stlb1=0;
    str2=0;
    stlb2=m-1;
    int left=0;//переменные для правого и левого треугольника
    int right=m-1;
    for(int i=0; i<=(n/2); ++i) //цикл перебирает строки с 0 по 2
    {
        for(int j=0; j<=left ; ++j) //Цикл перебирает левую верхнюю часть матрицы
        {
            if(array[i][j]>max1)
            {
                max1=array[i][j];
                str1=i;
                stlb1=j;
            }
        }
        ++left;
        for(int k=m-1; k>=right; k--) //цикл перебирающий правый треугольник, при этом у левого и правого треугольника может быть одно общее наибольшее число
        {
            if(array[i][k]>max2)
            {
                max2=array[i][k];
                str2=i;
                stlb2=k;
            }
        }
        --right;
    }
//cout<<max1<<" в "<<str1<<" строке"<<stlb1<<" столбце"<<endl;
//cout<<max2<<" в "<<str2<<" строке"<<stlb2<<" столбце"<<endl;

    left=(n/2)-1;
    right=m-1;
    int right2=1;
    int max3=array[0][0];
    int max4=array[0][m-1];
    int str3, stlb3, str4, stlb4;
    str3=0;
    stlb3=0;
    str4=0;
    stlb4=0;
    for(int i=(n/2)+1; i<n; ++i) //цикл перебирающий вторую половину матрицы(нижнюю часть квадрата)
    {
        for(int j=left; j>=0; --j) //цикл перебирающий левую нижнюю часть матрицы
        {
            if(array[i][j]>max3)
            {
                max3=array[i][j];
                str3=i;
                stlb3=j;
            }
        }
        --left;
        for(int k=right; k>=((n/2)+right2); --k)
        {
            if(array[i][k]>max4)
            {
                max4=array[i][k];
                str4=i;
                stlb4=k;
            }
        }
        ++right2;
    }
//cout<<max3<<endl;
//cout<<max4<<endl;
    int array_e[4]= {max1, max2, max3, max4}; //массив максимальных чисел четвертей матрицы для фигуры Е
    int max_e=array_e[0];//предполагаем, что max1 = максимальное значение
    for(int i=0; i<4; i++) //перебираем получившийся массив
    {
        if(array_e[i]>max_e)
        {
            max_e=array_e[i];
        }
    }

    if(max_e==max1)
    {
        cout<<"фигура Е максимальный элемент со значением "<<max1<<" находится в "<<str1<<" строке "<<stlb1<<" столбце"<<endl;
    }
    else
    {
        if(max_e==max2)
        {
            cout<<"фигура Е максимальный элемент со значением "<<max2<<" находится в "<<str2<<" строке "<<stlb2<<" столбце"<<endl;
        }
        else
        {
            if(max_e==max3)
            {
                cout<<"фигура Е максимальный элемент со значением "<<max3<<" находится в "<<str3<<" строке "<<stlb3<<" столбце"<<endl;
            }
            else
            {
                if(max_e==max4)
                {
                    cout<<"фигура Е максимальный элемент со значением "<<max4<<" находится в "<<str4<<" строке "<<stlb4<<" столбце"<<endl;
                }
            }
        }
    }
//cout<<"фигура Е максимальный элемент со значением "<<max_e<<endl;
//фигура Ж
    left=0;
    max1=array[0][0];
    str1=0;
    stlb1=0;
    str2=0;
    stlb2=m-1;
    int left2=1;
    for(int i=0; i<=(n/2); ++i) //цикл перебирает строки с 0 по 2
    {
        for(int j=0; j<=left; ++j)
        {
            if(array[i][j]>max1)
            {
                max1=array[i][j];
                str1=i;
                stlb1=j;
            }
        }
        ++left;
    }
//cout<<max1<<endl;
    max2=max1;
    for(int i=(n/2); i<n; ++i) //Цикл перебирает строки с 2 по 4
    {
        for(int j=(n/2)-left2; j>=0; --j) //перебираем столбцы с 2 по 0;
        {
            if(array[i][j]>max1)
            {
                max2=array[i][j];
                str2=i;
                stlb2=j;
            }
        }
    }
//cout<<max2<<endl;
    int array_G[3]= {max1, max2}; //запихиваем обе наибольше переменные в массив и находим большее, если они равны, условие не выполнится и значение max не измениться
    max=max1;
    for(int i=0; i<2; ++i)
    {
        if(array_G[i]>max)
        {
            max=array_G[i];
        }
    }
    if(max==max1)
    {
        cout<<"фигура Ж максимальный элемент со значением "<<max<<" находится в "<<str1<<" строке "<<stlb1<<" столбце"<<endl;
    }
    else
    {
        if(max==max2)
        {
            cout<<"фигура Ж максимальный элемент со значением "<<max<<" находится в "<<str2<<" строке "<<stlb2<<" столбце"<<endl;
        }
    }
//фигура З
    right=m-1;
    max1=array[0][m-1];
    right2=m/2;
    str1=0;
    stlb1=0;
    str2=0;
    stlb2=m-1;
    for(int i=0; i<=(n/2); ++i)
    {
        for(int j=m-1; j>=right	; --j)
        {
            if(array[i][j]>max1)
            {
                max1=array[i][j];
                str1=i;
                stlb1=j;
            }
        }
        --right;
    }
//cout<<max1<<endl;
    max2=max1;
    for(int i=(n/2); i<n; ++i)
    {
        for(int j=right2; j<m; ++j)
        {
            if(array[i][j]>max2)
            {
                max2=array[i][j];
                str2=i;
                stlb2=j;
            }
        }
        ++right2;
    }
//cout<<max2<<endl;
    int array_Z[2]= {max1, max2}; //запихиваем обе наибольше переменные в массив и находим большее, если они равны, условие не выполнится и значение max не измениться
    max=max1;
    for(int i=0; i<2; ++i)
    {
        if(array_Z[i]>max)
        {
            max=array_Z[i];
        }
    }
    if(max==max1)
    {
        cout<<"фигура З максимальный элемент со значением "<<max<<" находится в "<<str1<<" строке "<<stlb1<<" столбце"<<endl;
    }
    else
    {
        if(max==max2)
        {
            cout<<"фигура З максимальный элемент со значением "<<max<<" находится в "<<str2<<" строке "<<stlb2<<" столбце"<<endl;
        }
    }
//фигура И
    max=array[0][m-1];
    left=m;
    str=0;
    stlb=m-1;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<left; ++j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        --left;
    }
    cout<<"фигура И максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
//фигура К
    max=array[0][m-1];
    right=m-1;
    str=0;
    stlb=m-1;
    for(int i=0; i<n; ++i)
    {
        for(int j=m-1; j>=right; --j)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
                str=i;
                stlb=j;
            }
        }
        --right;
    }
    cout<<"фигура К максимальный элемент со значением "<<max<<" находится в "<<str<<" строке "<<stlb<<" столбце"<<endl;
    return 0;
}
