#include "header.h"
int create(int size, video *p)
{
    //size - это размерность самого массива, физически
    int choice, i;
    static int numOfFilms=6;//первоначальное количество фильмов в базе, его мы задаем вручную
    genre arrayGnr[]= {comedy, fantasy, fantastic};
    rate arrayRt[]= {bad, norm, cool};
    for(i=numOfFilms; i<size; ++i)
    {
        
        cout<<"\tВведите название фильма прописными русскими буквами,\n\tвместо пробела используйте _\n";
        cin>>(p+i)->title;
        cout<<"\tВведите фимилию режиссера\n";
        cin>>(p+i)->direct;
        cout<<"\tВыеберите жанр\n";
        cout<<"\t1 - COMEDY, 2 - FANTASY, 3 - FANTASTIC\n";
        cin>>choice;
        --choice;//получаем человечкский индекс элемента
        if(choice<=2&&choice>=0)
        {
            (p+i)->gnr=arrayGnr[choice];
        }
        else cout<<"\tНеверная опция. Повторите ввод\n";
        cout<<"\tКак вы оцениваете фильм 1 - плохо, 2 - нормально, 3 - хорошо\n";
        cin>>choice;
        --choice;
        if(choice<=2&&choice>=0)
        {
            (p+i)->rt=arrayRt[choice];
        }
        else cout<<"\tНеверная опция. Повторите ввод\n";
        cout<<"\tВведите стоимость\n";
        cin>>(p+i)->cost;
        cout<<"\tДобавить еще запись?\n\t1 - добавить\n\t2 - выход\n";
        cin>>choice;
        numOfFilms++;//делаем инкремент, для перехода при следующем обращении к новой ячейке памяти для хранения фильма
        if(choice!=1) break;
    }
    return numOfFilms;
}
/*
идея честно скопипащена у кульбицкого ну и немного принцип с куском кода
/ Функция добавления в файл
void addToFile(char* file){
	ofstream fout;
	fout.open(file,ios::binary|ios::out);
for (int i = 0; i < video.size(); ++i) {
	fout.write((char*)&video[i], sizeof (video[i]));
}
	fout.close();
}*/
