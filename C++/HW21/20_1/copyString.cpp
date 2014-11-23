#include "String.h"
void copyString() {
    int len=1024;
    String C(len);
    C.inToStream();
    String D(C);
    D.printToStream(cout);
}
