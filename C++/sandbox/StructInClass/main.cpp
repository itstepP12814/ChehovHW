#include <iostream>
#include "object.h"
using namespace std;

int main() {
    object ob1(1,2,3);
    object ob2(1,2,3);
    object ob3;
    ob3=ob1+ob2;
    ob3.show();
    return 0;
}
