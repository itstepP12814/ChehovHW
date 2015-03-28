#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <string>
#include <algorithm>
#define _UNICODE

using namespace std;

int main(){
	TCHAR* txt = L"Привет";
	_tprintf(TEXT("%s\n"), txt);
	locale mylocale("rus_rus.866");
	wcout.imbue(mylocale);

	wcout << txt << endl;
	vector<wstring> names = { TEXT("Чехов"), TEXT("Шмелев"), TEXT("Ололошка") };
	for (vector<wstring>::iterator it = names.begin(); it != names.end(); ++it){
		wcout << *it << endl;
	}
	sort(names.begin(), names.end());
	for (vector<wstring>::iterator it = names.begin(); it != names.end(); ++it){
		wcout << *it << endl;
	}
	return 0;
}