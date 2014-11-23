#include "setups.h"
void shipSetup() {
    static int human_ships[SIZE][SIZE]= {};
    cout<<"\tВведите координаты кораблей, всего 5 кораблей\n";

    display(human_ships);
}
