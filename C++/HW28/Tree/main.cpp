#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    Tree tbl;
    tbl["masha"]=1;
    tbl["lol"]=2;
    tbl["azazaza"]=3;
    tbl ["trolololo"]=4;
    tbl["kukumekuru"]=5;
    tbl.showTree(tbl.getRoot());
    return 0;
}
