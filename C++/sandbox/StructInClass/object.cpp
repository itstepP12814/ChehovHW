#include "object.h"
object::object(){
    s=NULL;
}
object::object(int a, int b, int c) {
    s=new stru;
    s->a=a;
    s->b=b;
    s->c=c;
    //ctor
}
object::object(const object& ob) {
    cout<<"copy constr\n"<<endl;
    s=new stru;
    s->a=ob.s->a;
    s->b=ob.s->b;
    s->c=ob.s->c;
}
void object::operator=(const object& ob1) {
    cout<<"operator=\n"<<endl;
    if(s=NULL){
        s=new stru;
    }
    //вот тут наступает сегфалт, почему непонятно, память выделяется выше в условии if
    s->a=ob1.s->a;
    s->b=ob1.s->b;
    s->c=ob1.s->c;
}
object object::operator+(const object& ob1){
    object ob2;
    ob2.s=new stru;
    ob2.s->a=this->s->a+ob1.s->a;
    ob2.s->b=this->s->b+ob1.s->b;
    ob2.s->c=this->s->c+ob1.s->c;
    return ob2;
}
void object::show()const {
    cout<<s->a<<endl;
    cout<<s->b<<endl;
    cout<<s->c<<endl;
}
object::~object() {
    //dtor
}
