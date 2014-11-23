#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array Ar;
    Ar[1]=20;
    for(int i=0; i<2; i++) {
        cout<<Ar[i]<<endl;
    }
    Ar[5];
    for(int i=0; i<5; i++) {
        cout<<Ar[i]<<endl;
    }
    return 0;
}
