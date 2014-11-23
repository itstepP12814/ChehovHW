#include"header.h"
void titleSearch(int size, video *p)
{
    char title_in[512];
    int check=1;//переменная определяет было ли хоть одно совпадение в поиске, если нет нам скажут, что ничего не найдено
    cout<<"\tВведите название картины прописными русскими,\n\tвместо пробела используйте \"_\"\n";
    cin>>title_in;
    for(int i=0; i<size; ++i)
    {
        if(strstr((p+i)->title, title_in))
        {
            cout<<"\tСовпадение найдено\n";
            result(p+i);
            check=0;
            cout<<endl;
        }
    }
    if(check) cout<<"\tСовпадений не найдено\n";
}
