#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <WinUser.h>
#include <Windowsx.h>
#include <vector>

using namespace std;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam); //оконная процедура запускается самой вендой
//аргументы: дескриптор окна, айди сообщения, доп.параметры, доп.параметры

void menuAction(WPARAM wParam);//menu switcher
double charsCount();

TCHAR szClassWindowName[] = TEXT("Мое первое гуи-приложение");//имя класса окна
struct Info{
	TCHAR title[20];
	TCHAR text[20];
	Info(TCHAR* _title, TCHAR* _text){
		wcscpy(title, _title);
		wcscpy(text, _text);
	}
};
vector<Info*> infos = { new Info(TEXT("Имя и фамилия"), TEXT("Павел Чехов")), new Info(TEXT("Возраст"), TEXT("24")), new Info(TEXT("Место работы"), TEXT("УО БГМУ")),
new Info(TEXT("Среднее число символов в тексте окон"), TEXT("")) };


INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPTSTR lpszCmdLine, int nCmdShow){
	/*арг: дескр приложухи, дескр приложухи которая запустила текущее приложение, указатель на строку для копирования аргументов при запуске из cmd.exe,
	способ визуализации окна при запуске программы*/
	HWND hWnd;//instance handle of the window class
	MSG Msg;//message struct
	WNDCLASSEX wcl;//window struct

	//1 declared window class
	wcl.cbSize = sizeof(wcl);//собстно размер самой стрктуры окна
	wcl.style = CS_HREDRAW | CS_VREDRAW;//стили окна говорят о том что окно будет перерисовано по вертикали и горизонтали
	wcl.lpfnWndProc = WindowProc;//адрес оконной процедуры, которую вызовет винда для обработки сообщений от окна
	wcl.cbClsExtra = 0;//count bytes, after struct of class window
	wcl.cbWndExtra = 0;//count bytes, after declared window
	wcl.hInstance = hInst;//handle current app
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);//load default icon application
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);//liad default cursor
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//fill window by white color
	wcl.lpszMenuName = NULL;//app not content menu
	wcl.lpszClassName = szClassWindowName;//set name for window class
	wcl.hIconSm = NULL;

	//2 register window class
	if (!RegisterClassEx(&wcl)) return 0;

	//3 create window
	hWnd = CreateWindowEx(
		0,//extension window style
		szClassWindowName,//name of window class
		TEXT("Резюме"),//title of window
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

	//4 show window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);//redrawind window

	//5 creaete menu
	HMENU MainMenu;
	HMENU  SubMenu;
	MainMenu = CreateMenu();
	SubMenu = CreateMenu();
	AppendMenu(MainMenu, MF_POPUP, (UINT_PTR)SubMenu, TEXT("Резюме"));
	AppendMenu(SubMenu, MF_STRING, 0, TEXT("ФИО"));
	AppendMenu(SubMenu, MF_STRING, 1, TEXT("Возраст"));
	AppendMenu(SubMenu, MF_STRING, 2, TEXT("Работа"));
	AppendMenu(SubMenu, MF_STRING, 3, TEXT("Среднее кол-во символов"));
	AppendMenu(MainMenu, MF_STRING, 4, TEXT("Выход"));

	SetMenu(hWnd, MainMenu);

	//6 processing for message queue
	while (GetMessage(&Msg, NULL, 0, 0)){
		//args for GetMessage - addres message struct, handle window, min number of recieved mesage, max number of recieved message
		TranslateMessage(&Msg);//translate message and put them in queue of window messages
		DispatchMessage(&Msg);//give the message to windows for processing
	}
	return Msg.wParam;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	switch (uMessage){
	case WM_COMMAND:
		menuAction(wParam);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);//this finction call WM_DESTROY and WM_NCDESTROY, clear message queue for current app, destroying window menu
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
void menuAction(WPARAM wParam){
	int res;
	vector<Info*>::iterator i = infos.begin();
	switch (wParam){
	case 0:
		res = MessageBox(0, (*(*(i + wParam))).text, (*(*(i + wParam))).title, MB_OK | MB_ICONINFORMATION);
		break;
	case 1:
		res = MessageBox(0, (*(*(i + wParam))).text, (*(*(i + wParam))).title, MB_OK | MB_ICONINFORMATION);
		break;
	case 2:
		res = MessageBox(0, (*(*(i + wParam))).text, (*(*(i + wParam))).title, MB_OK | MB_ICONINFORMATION);
		break;
	case 3:{
		double all_chars = charsCount();
		TCHAR buff[50];
		swprintf(buff, TEXT("Среднее число %f символов"), all_chars);//wsprintf doesnt work with qualifier %f
		res = MessageBox(0, buff, (*infos[2]).title, MB_OK | MB_ICONINFORMATION);
	}
		   break;
	case 4:
		res = MessageBox(0, TEXT("Вы уверены что хотите выйти?"), TEXT("Выход"), MB_YESNO | MB_ICONINFORMATION);
		if (res == IDYES) PostQuitMessage(0);
		break;
	}
}

double charsCount(){
	return ((double)(wcslen((*infos[0]).text) + (double)wcslen((*infos[1]).text)) / 3);
}