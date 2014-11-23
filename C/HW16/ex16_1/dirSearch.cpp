#include "header.h"
void dirSearch(int size, video *p)
{
    char direct_in[512];
    int check=1;
    cout<<"\tВведите Фамилию режиссера прописными русскими буквами,"<<"\n\tвместо пробела используйте \"_\"\n";
    cin>>direct_in;
    for(int i=0; i<size; ++i)
    {
        if(strstr((p+i)->direct, direct_in))
        {
            cout<<"\tСовпадение найдено\n";
            result(p+i);
            check=0;
            cout<<endl;
        }
    }
    if(check) cout<<"\tСовпадений не найдено\n";
}
