#include <windowsx.h>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include "resource.h"
using namespace std;

struct CELL{
	HWND hWnd;
	int stat;
};
BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
vector <CELL> CellVector;
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
		HWND hButton;
		hbmX = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP2));
		hbmO = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));
		for (int i = 0; i < 9; ++i){//содержим в массиве состояние кнопок
			hButton = GetDlgItem(hWnd, (IDC_BUTTON1 + i));
			CellVector.push_back({hButton, 0});
		}
	}	return TRUE;
	case WM_COMMAND: {
		LRESULT status = SendMessage(GetDlgItem(hWnd, IDC_CHECK_FIRST_STEP), BM_GETCHECK, 0, 0);
		for (int i = 0; i < 9; ++i){
			if (LOWORD(wParam) == (IDC_BUTTON1 + i)){
				HWND hButton = GetDlgItem(hWnd, (IDC_BUTTON1 + i));
				SendMessage(hButton, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmX));
				EnableWindow(hButton, 0);

				for (vector<CELL>::iterator i = CellVector.begin(); i != CellVector.end(); ++i){
					if (i->hWnd == hButton){
						i->stat = 1;
						break;
					}
				}
				for (auto x: CellVector){
					if (x.stat == 0){
						SendMessage(x.hWnd, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmO));
						EnableWindow(x.hWnd, 0);
						x.stat = 1;
						break;
					}
				}
				break;
			}
		}
		switch (wParam){
		case ID_EXIT: {
			int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) EndDialog(hWnd, 0);
		}break;
		case IDC_CHECK_FIRST_STEP:{
			//int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
		}break;
		}
	} return TRUE;
	default: return FALSE;
	}
}