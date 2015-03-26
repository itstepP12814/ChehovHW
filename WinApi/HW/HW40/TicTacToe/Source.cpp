#include <windowsx.h>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HBITMAP hbmX, hbmO;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch (msg){
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_INITDIALOG:{
		HMENU MainMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, MainMenu);
		hbmX = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));
		hbmO = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP2));
	}	return TRUE;
	case WM_COMMAND: {
		switch (wParam){
		case (ID_EXIT) : {
			int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) EndDialog(hWnd, 0);
			break;
		}break;
		case IDC_BUTTON1_1:{
			HWND hButton = GetDlgItem(hWnd, IDC_BUTTON1_1);
			SendMessage(hButton, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmX));
		} break;
		}
	} return TRUE;

	default: return FALSE;
	}
}