#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int cube_choice();//ф-ция выбора кто бросает кубики первым человек или машина
int cube_game(int a, int b);//сама игра с бросанием кубиков
void game_switch(int a);//переключалка вызывающая графическое изображение кубиков в зависимости от значения функции
void cube1();//графические изображения кубиков
void cube2();//хочется добавить, что хоть сами циклы кубиков нарисованы криво, но мне показалось что так они будут отображаться наилучшим образом
void cube3();//кубик с тройкой
void cube4();//с четверкой и т.д
void cube5();
void cube6();

int main()
{
    cube_choice();
    return 0;
}
int cube_choice()
{
    int choice;
    int cast=1;
    int count;
    cout<<"\t\tИгра кубики"<<endl;
    cout<<"\tвведите количество ходов"<<endl;
    cin>>count;
    cout<<"\tok, сейчас определится кто будет бросать первым, Вы или компьютер\n";
    srand(time(NULL));
    choice=rand()%2;//выбрасываются значения от 0 до 1;
    if(choice)
    {
        cout<<"\tПоздравляем Вы бросаете кубики первым\n";
        cube_game(cast=1, count);
    }
    else
    {
        cout<<"\tКомпьютер бросает кубики первым\n";
        cube_game(cast=0, count);
    }
    return 0;
}
int cube_game(int cast, int count)
{
    int cube1, cube2;
    int summ_human=0;//сумма бросков для человека
    int summ_pc=0;//сумма бросков для пк
    char input;
    int cnt=count;
    if (cast) //срабатывает если a=1 то есть если в cast записалось значение 1, т.е если первому бросать выпало человеку
    {
        for(int i=count; i>0; --i)
        {
            cout<<"\tнажмите P для броска\n";
            cout<<"\tосталось "<<i<<" бросков"<<endl;
            cin>>input;
            if(input!='\0') //Срабатвает если пользователь нажмет все, что угодно
            {
                //Первым бросает человек
                cube1=rand()%6+1;//выбрасывает значения кубика от 1 до 6 для 1 кубика;
                cube2=rand()%6+1;//то же самое для 2 кубика
                summ_human=summ_human+cube1+cube2;
                game_switch(cube1);
                game_switch(cube2);
                cout<<"\tВы выбросили "<<cube1<<" и "<<cube2<<" итог "<<cube1+cube2<<endl;
                cout<<"\tсейчас бросает компьютер"<<endl;
            }
            else {}
            //сейчас бросает компьютер
            cube1=rand()%6+1;//выбрасывает значения кубика от 1 до 6 для 1 кубика;
            cube2=rand()%6+1;//то же самое для 2 кубика
            summ_pc=summ_pc+cube1+cube2;
            game_switch(cube1);
            game_switch(cube2);
            cout<<"\tКомпьютер выбросил "<<cube1<<" и "<<cube2<<" итог "<<cube1+cube2<<endl;
        }
    }
    else //срабатывает если бросает компьютер a!=0;
    {
        for(int i=count; i>0; --i)
        {
            //сейчас бросает компьютер
            cube1=rand()%6+1;//выбрасывает значения кубика от 1 до 6 для 1 кубика;
            cube2=rand()%6+1;//то же самое для 2 кубика
            summ_pc=summ_pc+cube1+cube2;
            game_switch(cube1);
            game_switch(cube2);
            cout<<"\tКомпьютер выбросил "<<cube1<<" и "<<cube2<<" итог "<<cube1+cube2<<endl;
            //бросает человек
            cout<<"\tнажмите P для броска\n";
            cout<<"\tосталось "<<i<<" бросков"<<endl;
            cin>>input;
            if(input!='\0')
            {
                cube1=rand()%6+1;//выбрасывает значения кубика от 1 до 6 для 1 кубика;
                cube2=rand()%6+1;//то же самое для 2 кубика
                summ_human=summ_human+cube1+cube2;
                game_switch(cube1);
                game_switch(cube2);
                cout<<"\tВы выбросили "<<cube1<<" и "<<cube2<<" итог "<<cube1+cube2<<endl;
                cout<<"\tсейчас бросает компьютер"<<endl;
            }
            else {}
        }
    }
    if(summ_human>summ_pc)
    {
        cout<<"\tПоздравляем, Вы выиграли со счетом "<<summ_human<<":"<<summ_pc<<endl;
    }
    else
    {
        if(summ_human==summ_pc)
        {
            cout<<"\tничья со счетом "<<summ_human<<":"<<summ_pc<<endl;
        }
        else
        {
            cout<<"\tкомпьютер победил со счетом "<<summ_human<<":"<<summ_pc<<endl;
        }
    }
    return 0;
}
void game_switch(int a)
{
    switch (a)
    {
    case 1:
        cube1();
        break;
    case 2:
        cube2();
        break;
    case 3:
        cube3();
        break;
    case 4:
        cube4();
        break;
    case 5:
        cube5();
        break;
    case 6:
        cube6();
        break;
    default:
        break;
    }
}
void cube1()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if(i==a/2&&j==b/2)
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }
}
void cube2()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if(i==2&&(j==3||j==9))
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }
}
void cube3()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if((i==2&&j==3)||(i==2&&j==9)||(i==4&&j==3))
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }
}
void cube4()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if((i==1&&j==3)||(i==1&&j==9)||(i==3&&j==3)||(i==3&&j==9))
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }
}
void cube5()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if((i==1&&j==3)||(i==1&&j==9)||(i==3&&j==3)||(i==3&&j==9)||(i==5&&j==3))
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }
}
void cube6()
{
    int a=7;
    int b=13;
    for(int i=0; i<a; ++i)
    {
        if(i==0)
        {
            cout<<" ";
        }
        else
        {
            cout<<"|";
        }
        for(int j=0; j<b; ++j)
        {
            if(i==0||i==b/2)
            {
                cout<<"_";
            }
            else
            {
                if((i==1&&j==3)||(i==1&&j==9)||(i==3&&j==3)||(i==3&&j==9)||(i==5&&j==3)||(i==5&&j==9))
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if(i==0)
        {
            cout<<endl;
        }
        else
        {
            cout<<"|"<<endl;
        }
    }

}
