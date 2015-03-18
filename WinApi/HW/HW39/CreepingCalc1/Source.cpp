#include <windows.h>
#include <WinUser.h>
#include <tchar.h>
#include <stdlib.h>
#include <time.h>
#include "resource.h"
#define ID_TIMER 1
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimerProcRandom(HWND hwnd, UINT msg, UINT_PTR idTimer, DWORD dwTime);
void CALLBACK TimerProcLeft(HWND hwnd, UINT msg, UINT_PTR idTimer, DWORD dwTime);
void CALLBACK TimerProcRight(HWND hwnd, UINT msg, UINT_PTR idTimer, DWORD dwTime);
void CALLBACK TimerProcUp(HWND hwnd, UINT msg, UINT_PTR idTimer, DWORD dwTime);
void CALLBACK TimerProcDown(HWND hwnd, UINT msg, UINT_PTR idTimer, DWORD dwTime);
TCHAR szClassWindow[] = TEXT("Ползущий калькулятор");
HCURSOR hCursor1, hCursor2, hCursor3;

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
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
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Ползущий калькулятор"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	HMENU MainMenu;
	MainMenu = CreateMenu();
	AppendMenu(MainMenu, MF_STRING, 0, TEXT("Найти калькулятор"));
	AppendMenu(MainMenu, MF_STRING, 1, TEXT("Ползти"));
	AppendMenu(MainMenu, MF_STRING, 2, TEXT("Стоп"));
	AppendMenu(MainMenu, MF_STRING, 3, TEXT("Выход"));

	SetMenu(hWnd, MainMenu);


	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hCalc; int res = 0; UINT_PTR nTimerID;
	switch (uMessage)
	{
	case WM_CREATE:{
		HINSTANCE hInstance = GetModuleHandle(0);
		if (hInstance){
			hCursor1 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_NODROP));
			hCursor2 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_POINTER));
			hCursor3 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_POINTER_COPY));
		}
	}   break;
	case WM_COMMAND:{
		switch (wParam){
		case 0:{
			hCalc = FindWindow(TEXT("CalcFrame"), NULL);
			TCHAR caption[_MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
			GetWindowText(hCalc, caption, 100);//получаем текст заголовка нашего окна
			if (hCalc) res = MessageBox(0, caption, TEXT("Нашли!"), MB_OK | MB_ICONINFORMATION);
			else res = MessageBox(0, TEXT("Ненайдено"), TEXT("=("), MB_OK | MB_ICONINFORMATION);
		} break;
		case 1:{
			nTimerID = SetTimer(hWnd, ID_TIMER, 1, TimerProcRandom);
		} break;
		case 2:
			KillTimer(hWnd, ID_TIMER);
			break;
		case 3:
			res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) PostQuitMessage(0);
			break;
		default: break;
		}
	} break;
	case WM_KEYDOWN:{
		KillTimer(hWnd, ID_TIMER);
		switch (wParam){
		case '1':
			SetCursor(hCursor1);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor1)); // устанавливаем курсор
			break;
		case '2':
			SetCursor(hCursor2);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor2));
			break;
		case '3':
			SetCursor(hCursor3);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor3));
			break;
		case VK_LEFT:
			nTimerID = SetTimer(hWnd, ID_TIMER, 1, TimerProcLeft);
			break;
		case VK_RIGHT:
			nTimerID = SetTimer(hWnd, ID_TIMER, 1, TimerProcRight);
			break;
		case VK_UP:
			nTimerID = SetTimer(hWnd, ID_TIMER, 1, TimerProcUp);
			break;
		case VK_DOWN:
			nTimerID = SetTimer(hWnd, ID_TIMER, 1, TimerProcDown);
			break;
		default: break;
		}
	}break;
	case WM_DESTROY:
		KillTimer(hWnd, ID_TIMER);
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
void CALLBACK TimerProcRandom(HWND hWnd, UINT msg, UINT_PTR idTimer, DWORD dwTime){
	srand(time(NULL));
	HWND hCalc = FindWindow(TEXT("CalcFrame"), NULL);
	if (!hCalc) return;
	RECT oldRect;
	GetWindowRect(hCalc, &oldRect);
	int top = oldRect.top;
	int left = oldRect.left;
	int width = oldRect.right - oldRect.left;
	int height = oldRect.bottom - oldRect.top;
	if ((top >= 0 && top <= 1366) && (left >= 0 && left <= 768)){
		MoveWindow(hCalc, left + ((rand() % 50) - 25), top + ((rand() % 50) - 25), width, height, TRUE);
	}
	else {
		MoveWindow(hCalc, rand() % 800, rand() % 400, width, height, TRUE);
	}
}
void CALLBACK TimerProcLeft(HWND hWnd, UINT msg, UINT_PTR idTimer, DWORD dwTime){
	srand(time(NULL));
	HWND hCalc = FindWindow(TEXT("CalcFrame"), NULL);
	if (!hCalc) return;
	RECT oldRect;
	GetWindowRect(hCalc, &oldRect);
	int top = oldRect.top;
	int left = oldRect.left;
	int width = oldRect.right - oldRect.left;
	int height = oldRect.bottom - oldRect.top;
	if (left > 0){
		MoveWindow(hCalc, left - 5, top, width, height, TRUE);
	}
}
void CALLBACK TimerProcRight(HWND hWnd, UINT msg, UINT_PTR idTimer, DWORD dwTime){
	srand(time(NULL));
	HWND hCalc = FindWindow(TEXT("CalcFrame"), NULL);
	if (!hCalc) return;
	RECT oldRect;
	GetWindowRect(hCalc, &oldRect);
	int top = oldRect.top;
	int left = oldRect.left;
	int width = oldRect.right - oldRect.left;
	int height = oldRect.bottom - oldRect.top;
	if (left < 1366){
		MoveWindow(hCalc, left + 5, top, width, height, TRUE);
	}
}
void CALLBACK TimerProcDown(HWND hWnd, UINT msg, UINT_PTR idTimer, DWORD dwTime){
	srand(time(NULL));
	HWND hCalc = FindWindow(TEXT("CalcFrame"), NULL);
	if (!hCalc) return;
	RECT oldRect;
	GetWindowRect(hCalc, &oldRect);
	int top = oldRect.top;
	int left = oldRect.left;
	int width = oldRect.right - oldRect.left;
	int height = oldRect.bottom - oldRect.top;
	if (top < 768){
		MoveWindow(hCalc, left, top + 5, width, height, TRUE);
	}
}
void CALLBACK TimerProcUp(HWND hWnd, UINT msg, UINT_PTR idTimer, DWORD dwTime){
	srand(time(NULL));
	HWND hCalc = FindWindow(TEXT("CalcFrame"), NULL);
	if (!hCalc) return;
	RECT oldRect;
	GetWindowRect(hCalc, &oldRect);
	int top = oldRect.top;
	int left = oldRect.left;
	int width = oldRect.right - oldRect.left;
	int height = oldRect.bottom - oldRect.top;
	if (top > 0){
		MoveWindow(hCalc, left, top - 5, width, height, TRUE);
	}
}