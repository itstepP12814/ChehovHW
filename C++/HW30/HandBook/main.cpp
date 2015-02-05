#include "HandBook.h"

int main(){
	HandBook A;
	A.createFirm("Eggman", "Sonic", "123456798", "Nezavisimosti-88/74", "Audio");
	A.createFirm("Mars", "Chashbr", "84586566", "Liteynaya-19/22", "Video");
	A.createFirm("Pluton", "Ololoev", "845456566", "Sezam-17/43", "Computers");

	A.save();
	A.read();
	A.show();
}