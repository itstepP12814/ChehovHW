#include "header.h"
void writeToBase( int numOfFilms, video *p)
{
    /*функция очень похожа на result, только вместо cout у нас fout;
    правда пока что после каждого перезапуска функция переписывает фал базы заново, не сохраняя старых изменений*/
    char filename[50];
    ofstream fout;
    cout<<"\tВведите имя файла базы, без расширения\n";
    scanf("%s", &filename);
    strcat(filename, ".txt");//добавление расширения к имени файла
    fout.open(filename);
    for(int i=0; i<numOfFilms; ++i)
    {
        char* genre[]= {"Комедия","Фэнтези","Фантастика"};
        char* rate[]= {"Плохо", "Нормально", "Хорошо"};
        int g=(p+i)->gnr;//присваиваем переменным числовые значения из перечислений жанра
        int r=(p+i)->rt;//рейтинга
        fout<<"\tНазвание: "<<(p+i)->title<<endl;
        fout<<"\tРежжисер: "<<(p+i)->direct<<endl;
        fout<<"\tЖанр: "<<genre[g]<<endl;//выводим значения из массивов
        fout<<"\tРейтинг: "<<rate[r]<<endl;
        fout<<"\tСтоимость: "<<(p+i)->cost<<"\n\n";
    }
    fout.close();
    cout<<"\tФайл базы переаписан\n"<<filename<<" расположен в корневом катологе программы\n";
}
