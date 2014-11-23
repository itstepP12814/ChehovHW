#include "setups.h"
void display(int field[SIZE][SIZE]) {
    for(int i=0; i< SIZE; ++i) {
        for(int j=0; j<SIZE; ++j) {
            cout<<field[i][j];
        }
        cout<<endl;
    }
}
