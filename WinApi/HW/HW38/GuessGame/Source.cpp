#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <time.h>
#include <WinUser.h>
#include <Windowsx.h>
#include <vector>

using namespace std;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

TCHAR szClassWindowName[] = TEXT("Угадай число");//имя класса окна

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPTSTR lpszCmdLine, int nCmdShow){
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;


	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindowName;
	wcl.hIconSm = NULL;

	if (!RegisterClassEx(&wcl)) return 0;

	hWnd = CreateWindowEx(
		0,//extension window style
		szClassWindowName,//name of window class
		TEXT("Угадай число"),//title of window
		WS_OVERLAPPEDWINDOW,//window style
		/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х
		CW_USEDEFAULT,	// y
		CW_USEDEFAULT,	// width window
		CW_USEDEFAULT,	// heght window
		NULL,//handle parent window
		NULL,//handle main menu
		hInst,//handle app
		NULL//pointer to the applications data
		);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);//redrawind window

	TCHAR buff[50];
	srand(time(NULL));
	//6 processing for message queue
	while (GetMessage(&Msg, NULL, 0, 0)){
		//args for GetMessage - addres message struct, handle window, min number of recieved mesage, max number of recieved message
		TranslateMessage(&Msg);//translate message and put them in queue of window messages
		int ran = rand() % 100;
		wsprintf(buff, TEXT("Число %d"), ran);
		int res = MessageBox(0, buff, TEXT("Угадали?"), MB_YESNO | MB_ICONINFORMATION);
		switch (res){
		case IDYES:
			res = MessageBox(0, TEXT("Выход?"), TEXT("Выйти?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) PostQuitMessage(0);
			break;
		default: break;
		}
		DispatchMessage(&Msg);//give the message to windows for processing
	}
	return Msg.wParam;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	switch (uMessage){
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
		break;
	}
	return 0;
}