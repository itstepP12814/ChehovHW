#include <iostream>
#include "Gai_tree.h"
using namespace std;
int main() {
	Gai_tree A;
	A["1230"] = { 8, 9, 6 };
	A["1231"] = { 9, 7, 6 };
	A["C123PF"] = { 457, 247, 817 };
	A["A123AA"] = { 47, 21, 87 };
	A["C123BG"] = { 23, 65, 1 };
	A["C123CC"] = { 54, 23, 65 };
	A.showTree(getRoot(A));
	A.search("1235", getRoot(A));
	A.searchDiapasone("A123AA", "C123FF", getRoot(A));
	return 0;
}