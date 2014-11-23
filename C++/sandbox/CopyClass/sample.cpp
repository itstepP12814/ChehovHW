#include "sample.h"
sample::sample(int x, int y)
{
	a=x;
	b=y;
	//ctor
}

sample::~sample()
{
	//dtor
}

void sample::print() {
    cout<<a<<" "<<b;
}
