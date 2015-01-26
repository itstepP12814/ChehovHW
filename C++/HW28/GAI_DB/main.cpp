#include <iostream>
#include "Gai_tree.h"
using namespace std;
int main() {
	Gai_tree A;
	A["1230"] = { 8, 9, 6 };
	A["1231"] = { 9, 7, 6 };
	A["1232"] = { 457, 247, 817 };
	A["1233"] = { 47, 21, 87 };
	A["1234"] = { 23, 65, 1 };
	A["1235"] = { 54, 23, 65 };
	A.showTree(getRoot(A));
	A.search("1235", getRoot(A));
	A.searchDiapasone("1231", "1234", getRoot(A));
	return 0;
}