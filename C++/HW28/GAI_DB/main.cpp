#include <iostream>
#include "Gai_tree.h"
using namespace std;

int main() {
	Gai_tree A;
	A["50852468"] = { 8, 9, 6 };
	A.showTree(A.getRoot());
	return 0;
}