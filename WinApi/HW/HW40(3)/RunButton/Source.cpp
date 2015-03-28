#include <windowsx.h>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "resource.h"
using namespace std;

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int TOP, LEFT;
//отладочное окно
TCHAR szText[50]; HWND hInfo;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch (msg){
	case WM_CLOSE: EndDialog(hWnd, 0);
		return TRUE;
	case WM_MOUSEMOVE:{
		TOP = GET_Y_LPARAM(lParam);
		LEFT = GET_X_LPARAM(lParam);
		RECT rButton, rDlg, rClientWindow;
		GetWindowRect(GetDlgItem(hWnd, IDPRESS), &rButton);
		GetWindowRect(hWnd, &rDlg);
		GetClientRect(hWnd, &rClientWindow);
		int top = rButton.top - rDlg.top - 50;
		int left = rButton.left - rDlg.left - 15;
		int width = rButton.right - rButton.left;
		int height = rButton.bottom - rButton.top;
		int right = width + left + 10;
		int bottom = height + top + 15;
		srand(time(NULL));
		if ((TOP >= top && TOP <= bottom) && (LEFT >= left && LEFT <= right)){
			if ((top > 0 && top < rClientWindow.bottom-height-10) && (left>0 && left< rClientWindow.right-width-10))
				MoveWindow(GetDlgItem(hWnd, IDPRESS), left + (rand() % 40 - 15), top + (rand() % 40 - 15),
				width, height, TRUE);
		}
	} return TRUE;
	}
	return FALSE;
}