#ifndef ROUNDING_H
#define ROUNDING_H
#include <iostream>
using namespace std;
template <typename I, typename D> D rounding(I n, D a)
{
    cout<<"\t\tчисло округлено до "<<n<<" знаков после запятой"<<endl;
    cout<<setprecision(n+1)<<a<<endl;
    return 0;
}

#endif // ROUNDING_H
