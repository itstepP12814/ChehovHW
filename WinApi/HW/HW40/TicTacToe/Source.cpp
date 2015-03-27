#include <windowsx.h>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "resource.h"
using namespace std;
#define AI_STEP 111555 //это код моего собственного сообщения, означающего что ИИ может сделать ход

struct CELL{
	HWND hWnd;
	int stat;//статус 1-кнопка была нажата 0 - не нажата
	int sign;//ID знака 1- крестик 0-нолик
};

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int Compare(HWND hWnd);
vector <CELL> CellVector;
HBITMAP hbmX, hbmO;

//отладочное окно
TCHAR szText[30]; HWND hInfo;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	static int FLAG = 0;//Флаг.По умолчанию 0, если первым пошел человек(крестиками), иначе он станет 1, значит первым пошел комп(крестиками)
	switch (msg){
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	case WM_INITDIALOG:{
		HMENU MainMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, MainMenu);
		hbmX = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP2));
		hbmO = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));
		SetFocus(GetDlgItem(hWnd, IDC_RADIO_MEDIUM));
		SetFocus(GetDlgItem(hWnd, IDC_BUTTON4));
		DWORD dwError = GetLastError();

		HWND hButton;
		for (int i = 0; i < 9; ++i){//содержим в массиве состояние кнопок
			hButton = GetDlgItem(hWnd, (IDC_BUTTON1 + i));
			CellVector.push_back({ hButton, 0, 0 });
		}
	}	return TRUE;
	case WM_COMMAND: {
		for (int i = 0; i < 9; ++i){
			if (LOWORD(wParam) == (IDC_BUTTON1 + i) && HIWORD(wParam) == BN_CLICKED){
				vector<CELL>::iterator it = (CellVector.begin() + i);
				if (it->stat == 0){
					if (FLAG == 1){
						SendMessage(it->hWnd, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmO));
						it->sign = 0;
					}
					else {
						SendMessage(it->hWnd, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmX));
						it->sign = 1;
					}
					EnableWindow(it->hWnd, 0);
					it->stat = 1;
				}
				Compare(hWnd);
				SendMessage(hWnd, AI_STEP, 0, 0);
				EnableWindow(GetDlgItem(hWnd, IDC_CHECK_FIRST_STEP), 0);
				break;
			}
		}
		switch (wParam){
		case ID_EXIT: {
			int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) EndDialog(hWnd, 0);
		}break;
		case IDC_CHECK_FIRST_STEP:{
			LRESULT status = SendMessage(GetDlgItem(hWnd, IDC_CHECK_FIRST_STEP), BM_GETCHECK, 0, 0);
			if (status == BST_CHECKED){
				wsprintf(szText, TEXT("ИИ делает первый ход"), AI_STEP);
				SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), szText);
				FLAG = 1;
				EnableWindow(GetDlgItem(hWnd, IDC_CHECK_FIRST_STEP), 0);
				SendMessage(hWnd, AI_STEP, 0, 0);
			}
		}break;
		case ID_NEW_GAME:{
			for (vector<CELL>::iterator it = CellVector.begin(); it != CellVector.end(); ++it){
				it->stat = 0;
				it->sign = 0;
				SendMessage(it->hWnd, BM_SETIMAGE, 0, 0);
				EnableWindow(it->hWnd, 1);
			}
			SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), TEXT("Начните новую игру"));
			EnableWindow(GetDlgItem(hWnd, IDC_CHECK_FIRST_STEP), 1);
			CheckDlgButton(hWnd, IDC_CHECK_FIRST_STEP, BST_UNCHECKED);
			FLAG = 0;
		}break;
		}
	} return TRUE;
	case AI_STEP:{
		srand(time(NULL));
		vector<HWND> FreeButtons;//Вектор с хэндлами пока не нажатых кнопок, между ними мы разыграем рулетку
		vector<HWND>::iterator itFreeButtons;
		for (vector<CELL>::iterator it = CellVector.begin(); it != CellVector.end(); ++it){
			if (it->stat == 0) FreeButtons.push_back(it->hWnd);
		}
		if (FreeButtons.size() == 0) return TRUE; //если все кнопки нажаты прерываем обработку

		int r = rand() % FreeButtons.size();
		itFreeButtons = FreeButtons.begin() + r;//в итератор запишется рандомный номер какого-то элемента массива из ненажатых кнопок

		for (vector<CELL>::iterator it = CellVector.begin(); it != CellVector.end(); ++it){
			if (it->hWnd == (*itFreeButtons)){
				if (FLAG == 1){
					SendMessage(it->hWnd, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmX));
					it->sign = 1;
				}
				else {
					SendMessage(it->hWnd, BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hbmO));
					it->sign = 0;
				}
				EnableWindow(it->hWnd, 0);
				it->stat = 1;
				break;
			}
		}
		FreeButtons.clear();
		Compare(hWnd);
	} return TRUE;
	default: return FALSE;
	}
}

int Compare(HWND hWnd){
	vector<CELL>::iterator it = CellVector.begin();
	for (int i = 0; i < 3; ++i){//проверяем столбцы
		if (it->stat == 1 && (it + 3)->stat == 1 && (it + 6)->stat == 1){
			if (it->sign == (it + 3)->sign && (it + 3)->sign == (it + 6)->sign){
				if (it->sign == 1) wsprintf(szText, TEXT("Победили X"));
				else wsprintf(szText, TEXT("Победили O"));
				SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), szText);
				break;
			}
		}
		it++;
	}
	it = CellVector.begin();
	for (int i = 0; i < 3; ++i){//строки
		if (it->stat == 1 && (it + 1)->stat == 1 && (it + 2)->stat == 1){
			if (it->sign == (it + 1)->sign && (it + 1)->sign == (it + 2)->sign){
				if (it->sign == 1) wsprintf(szText, TEXT("Победили X"));
				else wsprintf(szText, TEXT("Победили O"));
				SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), szText);
				break;
			}
		}
		it++;
	}
	it = CellVector.begin();
	//диагонали
	if (it->stat == 1 && (it + 4)->stat == 1 && (it + 8)->stat == 1){
		if (it->sign == (it + 4)->sign && (it + 4)->sign == (it + 8)->sign){
			if (it->sign == 1) wsprintf(szText, TEXT("Победили X"));
			else wsprintf(szText, TEXT("Победили O"));
			SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), szText);
		}
	}
	if ((it+2)->stat == 1 && (it + 4)->stat == 1 && (it + 6)->stat == 1){
		if ((it+2)->sign == (it + 4)->sign && (it + 4)->sign == (it + 6)->sign){
			if (it->sign == 1) wsprintf(szText, TEXT("Победили X"));
			else wsprintf(szText, TEXT("Победили O"));
			SetWindowText(GetDlgItem(hWnd, IDC_STATIC1), szText);
		}
	}
	return 0;
}