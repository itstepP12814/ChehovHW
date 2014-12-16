#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Roll.h"
using namespace std;

int main() {
    srand(time(NULL));
    int count1=rand()%15000;
    int count2=rand()%25000;
    int count3=rand()%30000;
    int count4=rand()%35000;
    int count5=rand()%40000;
    Roll A, B, C, D, E;
    char a, b, c, d, e;
    cout<< "\tStart the game\n";
    a=A.rotateRoll(count1);
    b=B.rotateRoll(count2);
    c=C.rotateRoll(count3);
    d=D.rotateRoll(count4);
    e=E.rotateRoll(count5);
    if(a==b&&b==c&&c==d&&d==e) {
        cout<< "\tYOU WIN!"<<endl;
    } else if(a==b&&b==c&&c==d||b==c&&c==d&&d==e) {
        cout<< "\tYOU WIN 3 FREE GAMES!"<<endl;
    } else if (a==b&&b==c||c==d&&d==e||b==c&&c==d) {
        cout<< "\tYOU WIN 1 FREE GAME!"<<endl;
    } else cout<< "\tYOU LOOSE!"<<endl;
    return 0;
}
