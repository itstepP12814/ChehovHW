#include "Roll.h"

Roll::Roll():size(5) {
    //ctor
}

Roll::~Roll() {
    //dtor
}
char Roll::rotateRoll(int count) {
    //Метод вращает барабан
    for(int k=0; k<count; ++k) {
        char temp=symb[0];
        for(int i=1; i<size; ++i) {
            symb[i-1]=symb[i];
        }
        symb[size-1]=temp;
        printf("\t|| %c ||\r", symb[0]);
    }
    printf("\n");
    return symb[0];
}
void Roll::showRoll() const {
    for(int i=0; i<size; ++i) {
        cout<< symb[i]<< " ";
    }
    cout<<endl;
}
