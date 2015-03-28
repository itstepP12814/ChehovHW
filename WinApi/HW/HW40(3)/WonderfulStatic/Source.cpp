#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>
#include "resource.h"
using namespace std;

struct INFO{
	HWND hWnd;
	int num;
	RECT Rect;
};
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hStatic, hStaticInfo; HINSTANCE hInst;
TCHAR szCoordinates[50]; TCHAR szNumber[20];
vector <INFO> hVector;
int TOP, LEFT, BOTTOM, RIGHT, WIDTH, HEIGHT;//y1 x1, y2 x2
//GET_Y_LPARAM(lParam) - положение по y 
//GET_X_LPARAM(lParam) - положение курсора по х
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	static int count = 0;
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
		if (HEIGHT >= 10 && WIDTH >= 10){
			hStatic = CreateWindowEx(0, TEXT("STATIC"), 0,
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
				LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);
			SetClassLong(hStatic, GCL_STYLE, CS_DBLCLKS);
			wsprintf(szNumber, TEXT("№ %d"), ++count);
			SetWindowText(hStatic, szNumber);	// строка выводится на статик
			hVector.push_back({ hStatic, count, { LEFT, TOP, RIGHT, BOTTOM } });
		}
		else {
			if ((HEIGHT < 10 && HEIGHT>7) && (WIDTH > 7 && WIDTH < 10))
				int res = MessageBox(0, TEXT("Слишком маленький размер"), TEXT("Предупреждение!"), MB_OK | MB_ICONINFORMATION);
		}
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
			for (vector<INFO>::iterator i = hVector.begin(); i != hVector.end(); ++i){
				DestroyWindow(i->hWnd);
			}
			hVector.clear();
			break;
		} return TRUE;
	case WM_RBUTTONDOWN:{//-2px
		int TOP_M = GET_Y_LPARAM(lParam);
		int LEFT_M = GET_X_LPARAM(lParam);
		int width, height;
		for (vector<INFO>::iterator i = hVector.begin(); i != hVector.end(); ++i){
			width = i->Rect.right - i->Rect.left;
			height = i->Rect.bottom - i->Rect.top;

			if ((LEFT_M >= i->Rect.left  && LEFT_M <= i->Rect.right) && (TOP_M >= i->Rect.top && TOP_M <= i->Rect.bottom)){
				wsprintf(szCoordinates, TEXT("TOP=%d LEFT=%d\nBOTTOM=%d RIGHT=%d\nHEIGHT=%d WIDTH=%d"), i->Rect.top, i->Rect.left, i->Rect.bottom, i->Rect.right, height, width);
				SetWindowText(hWnd, szCoordinates);
				SetWindowText(hStaticInfo, szCoordinates);
			}
		}
	} return TRUE;
	case WM_LBUTTONDBLCLK:{
		int TOP_M = GET_Y_LPARAM(lParam);
		int LEFT_M = GET_X_LPARAM(lParam);
		for (vector<INFO>::iterator i = hVector.begin(); i != hVector.end(); ++i){
			if ((LEFT_M >= i->Rect.left  && LEFT_M <= i->Rect.right) && (TOP_M >= i->Rect.top && TOP_M <= i->Rect.bottom)){
				DestroyWindow(i->hWnd);
				hVector.erase(i);
				break;
			}
		}
	}  return TRUE;
	}
	return FALSE;
}