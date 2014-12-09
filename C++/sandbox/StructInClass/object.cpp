#include "object.h"

object::object() {
    s=new stru;
    s->a=1;
    s->b=2;
    s->c=3;
    //ctor
}

object::~object() {
    //dtor
}
