#include <windows.h>
#include "resource.h"
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
HICON hIcon;
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
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Курсоры"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_CREATE: {
		//инициализация дескрипторов курсоров
		HINSTANCE hInstance = GetModuleHandle(0);
		hCursor1 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_NODROP));
		hCursor2 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_POINTER));
		hCursor3 = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_POINTER_COPY));
	} break;
	case WM_KEYDOWN:{
		switch (wParam){
		case '1':
			SetCursor(hCursor1);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor1)); // устанавливаем курсор
			break;
		case '2':
			SetCursor(hCursor2);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor2)); // устанавливаем курсор
			break;
		case '3':
			SetCursor(hCursor3);
			SetClassLong(hWnd, GCL_HCURSOR, LONG(hCursor3)); // устанавливаем курсор
			break;
		default: break;
		}
	}break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}