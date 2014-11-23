#include "counter.h"
#include <iostream>
using namespace std;
counter::counter(int x, int y) {
    counter::min=y;
    counter::max=x;
    counter::count=y;//изначально равняется минимальному значению
    //ctor
}

counter::~counter() {
    //dtor
}
