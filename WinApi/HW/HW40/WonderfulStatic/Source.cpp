#include <windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hStatic, hStaticInfo; HINSTANCE hInst;
TCHAR szCoordinates[40]; TCHAR szNumber[10];
int TOP, LEFT, BOTTOM, RIGHT, WIDTH, HEIGHT;//x1 y1, x2 y2
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch (msg){
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_INITDIALOG:
		hStaticInfo = GetDlgItem(hWnd, IDC_STATIC1);
		return TRUE;
	case WM_LBUTTONDOWN:
		//LOWORD(lParam) - положение курсора по х
		//HIWORD(lParam) - положение по у
		TOP = HIWORD(lParam);
		LEFT = LOWORD(lParam); 
		return TRUE;
	case WM_LBUTTONUP:
		BOTTOM = HIWORD(lParam);
		RIGHT = LOWORD(lParam);
		HEIGHT = BOTTOM - TOP;
		WIDTH = RIGHT - LEFT;
		hStatic = CreateWindowEx(0, TEXT("STATIC"), 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
			LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);
		wsprintf(szNumber, TEXT("№ 1"));
		SetWindowText(hStatic, szNumber);	// строка выводится на статик
		return TRUE;
	case WM_MOUSEMOVE:
		wsprintf(szCoordinates, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // текущие координаты курсора мыши
		SetWindowText(hStaticInfo, szCoordinates);	// строка выводится на статик
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case IDINFO:
			wsprintf(szCoordinates, TEXT("TOP=%d LEFT=%d\nBOTTOM=%d RIGHT=%d\nHEIGHT=%d WIDTH=%d"), TOP, LEFT, BOTTOM, RIGHT, HEIGHT, WIDTH); // текущие координаты курсора мыши
			SetWindowText(hStaticInfo, szCoordinates);
			break;
		case IDCANCEL:
			if (hStatic)
				DestroyWindow(hStatic);
			break;
		} return TRUE;
	}
	return FALSE;
}