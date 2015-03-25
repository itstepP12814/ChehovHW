#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>
#include "resource.h"
using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hStatic, hStaticInfo; HINSTANCE hInst;
TCHAR szCoordinates[50]; TCHAR szNumber[20];
vector <HWND> hVector;
int TOP, LEFT, BOTTOM, RIGHT, WIDTH, HEIGHT,
top, bottom, left, right, width, height;//y1 x1, y2 x2
//GET_Y_LPARAM(lParam) - положение по y 
		//GET_X_LPARAM(lParam) - положение курсора по х
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
		TOP = GET_Y_LPARAM(lParam);
		LEFT = GET_X_LPARAM(lParam);
		return TRUE;
	case WM_LBUTTONUP:{
		BOTTOM = GET_Y_LPARAM(lParam);
		RIGHT = GET_X_LPARAM(lParam);
		HEIGHT = BOTTOM - TOP;
		WIDTH = RIGHT - LEFT;
		hStatic = CreateWindowEx(0, TEXT("STATIC"), 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
			LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);
		wsprintf(szNumber, TEXT("№ 1"));
		SetWindowText(hStatic, szNumber);	// строка выводится на статик
		hVector.push_back(hStatic);
	}	return TRUE;
	case WM_MOUSEMOVE:
		wsprintf(szCoordinates, TEXT("X=%d Y=%d "), GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)); // текущие координаты курсора мыши
		SetWindowText(hStaticInfo, szCoordinates);	// строка выводится на статик
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)){
		case IDINFO:
			wsprintf(szCoordinates, TEXT("TOP(Y)=%d LEFT(X)=%d\nBOTTOM(Y)=%d RIGHT(X)=%d\nHEIGHT=%d WIDTH=%d"), TOP, LEFT, BOTTOM, RIGHT, HEIGHT, WIDTH); // текущие координаты курсора мыши
			SetWindowText(hStaticInfo, szCoordinates);
			break;
		case IDCANCEL:
			for (vector<HWND>::iterator i = hVector.begin(); i != hVector.end(); ++i){
				DestroyWindow(*i);
			}
			hVector.clear();
			break;
		} return TRUE;
	case WM_RBUTTONDOWN:{
		RECT Rect, dlgRect;
		int TOP_M = GET_Y_LPARAM(lParam);
		int LEFT_M = GET_X_LPARAM(lParam);
		if (hStatic){
			GetWindowRect(hStatic, &Rect);
			GetWindowRect(hWnd, &dlgRect);
			top = Rect.top-dlgRect.top;
			left = Rect.left-dlgRect.left;
			width = Rect.right - Rect.left;
			height = Rect.bottom - Rect.top;
			right = width+left;
			bottom = height+top;
			wsprintf(szCoordinates, TEXT("TOP(Y)=%d LEFT(X)=%d\nBOTTOM(Y)=%d RIGHT(X)=%d\nHEIGHT=%d WIDTH=%d"), top, left, bottom, right, height, width);
			SetWindowText(hStaticInfo, szCoordinates);

			/*if ((LEFT >= left && LEFT <= right) && (TOP >= top && TOP <= bottom)){
				wsprintf(szCoordinates, TEXT("TOP(Y)=%d LEFT(X)=%d\nBOTTOM(Y)=%d RIGHT(X)=%d\nHEIGHT=%d WIDTH=%d"), top, left, bottom, right, height, width);
				SetWindowText(hStaticInfo, szCoordinates);
				}*/
		}
	} return TRUE;
	}
	return FALSE;
}