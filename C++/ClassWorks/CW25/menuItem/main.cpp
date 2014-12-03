#include <cstring>
#include <iostream>
#include "menuitem.h"
using namespace std;

int main() {
    MenuItem* x[256]= {};
    char z;
    x['1']=new GavItem();
    x['2']=new KukuItem();
    x['e']=new ExitItem();
    cin>>z;
    if(x[z]!=NULL) {
        (*x[z])();
    }
    delete x['1'];
    delete x['2'];
    delete x['e'];
    return 0;
}
