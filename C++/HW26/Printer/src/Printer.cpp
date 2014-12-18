#include "Printer.h"

Printer::Printer() {
    //ctor
}
Printer::Printer(int c) {
    queue=(Client*)malloc(sizeof(Client)*c);
    users=(user*)malloc(sizeof(user)*c);
    count=0;
    max=c;
}
Printer::~Printer() {
    free(queue);
    free(users);
    //dtor
}
void Printer::resize() {
    queue=(Client*)realloc(queue, max*2*sizeof(Client));
    users=(user*)realloc(users, max*2*sizeof(user));
    max*=2;
}
void Printer::setQueue(const Client A) {
    /*тут приницпиально возможны три ситуации 1)элемент самый первый, и очередь до него пуста - выполняется первый иф
    2)элемент находит свое место в очереди, т.е у него не самый большой и не самый маленький приоритет
    3)элемент не находит свое место в очереди, у него самый маленький приоритет, и мы должны поставить его в конец очереди
    два последних варианта высчитывает метод insert
    */
    //нам нужно вставить его в уонец очереди
    if(count==0) {//для самого первого элемента очереди
        queue[0]=A;
        users[0].id=count+1;
        users[0].time=A.pages;
        ++count;
    } else {//для всех последующих элементов
        if(count<max) {//проверяем есть ли место в очереди
            insert(A);
        } else {//если место в очереди закончилось делаем переразметку адресного пространства и еще раз вставляем элемент
            resize();
            insert(A);
        }
    }
}
void Printer::insert(const Client A) {
    int indicator=1;
    Client temp_client;
    user temp_user;
    for(int i=0; i<count; ++i) {//ищем после какого элемента нам расположить входящий новый элемент
        if(A.prior>queue[i].prior) {// если нашли место, то сдвигаем все элементы вправо от входящего
            for(int j=count-1; j>=i; --j) {
                queue[j+1]=queue[j];
                users[j+1]=users[j];
            }
            //записываем на нужное место новый элемент
            queue[i]=A;
            users[i].id=count+1;
            users[i].time=A.pages;
            ++count;
            indicator=0;//нулевой индикатор говорит о том, что в конец очереди писать ничего не надо
            break;
        }
    }
    if(indicator) { //Если не нашли элемент с меньшим приоритетом, значит нам поступил элемент
        //с самым маленьким приоритетом т.е новый элемент становиться в конец очереди
        queue[count]=A;
        users[count].id=count+1;
        users[count].time=A.pages;
        ++count;
    }
}
void Printer::print()const {
    for(int i=0; i<count; ++i) {
        cout<<"id "<<users[i].id<<endl;
        cout<<"priority "<<queue[i].prior<<endl;
        cout<<"time "<<users[i].time<<endl;
        cout<<endl;
    }
}
