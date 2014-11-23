#include "String.h"
void initString() {
    cout<<"\tВведите длину строки\n";
    int len;
    cin>>len;
    String B(len);
    B.inToStream();
    B.printToStream(cout);
}
