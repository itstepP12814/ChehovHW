#include "honoe_tower.h"
int main()
{
    int disks=3;
    int to_pyramid=3;
    cout<<"\tвведи количество дисков\n";
    cin>>disks;
    cout<<"\tвведи номер пирамиды на котррую надо перемещать диски( 2 или 3)\n";
    cin>>to_pyramid;
    switcher(disks, to_pyramid);
    return 0;
}
