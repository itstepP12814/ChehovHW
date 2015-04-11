#include <tchar.h>
#include <windows.h>
#include <WinUser.h>
#include <Windowsx.h>
#include <iostream>

using namespace std;

long long unsigned int x = 0;
CRITICAL_SECTION cs;

DWORD WINAPI Thread1(LPVOID lp)
{
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10000000; i++)
	{
		InterlockedIncrement(&x);
		//++x;
	}
	LeaveCriticalSection(&cs);
	cout << "first thread end\n";
	return 0;
}

DWORD WINAPI Thread2(LPVOID lp)
{
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10000000; i++)
	{
		InterlockedIncrement(&x);
		//--x;
	}
	LeaveCriticalSection(&cs);
	cout << "second thread end\n";
	return 0;
}

int main(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow){
	InitializeCriticalSection(&cs);

	HANDLE inc=CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
	HANDLE dec=CreateThread(NULL, 0, Thread2, NULL, 0, NULL);
	WaitForSingleObject(inc, INFINITE);
	WaitForSingleObject(dec, INFINITE);
	DeleteCriticalSection(&cs);
	cout << x << endl;
	return 0;
}