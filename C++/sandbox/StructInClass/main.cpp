#include <iostream>
#include "object.h"
using namespace std;

int main() {
    stru* p=new stru;
    p->a=1;
    p->b=2;
    p->c=3;
    cout<<p->a<<endl;
    cout<<p->b<<endl;
    cout<<p->c<<endl;
    object a;
    cout<<a.s->a<<endl;
    cout<<a.s->b<<endl;
    cout<<a.s->c<<endl;
    return 0;
}
