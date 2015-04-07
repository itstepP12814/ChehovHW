#include <windowsx.h>
#include <Windows.h>
#include <vector>
#include <tchar.h>
#include "resource.h"
#include <string>
#include <map>

using namespace std;

enum Digits { Empty, Digit };
TCHAR szText[20];
int LEFT = 0, TOP = 0, HEIGHT = 50, WIDTH = 50;
HINSTANCE hInst;
BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class Model{
public:
	Model(size_t height_, size_t width_) : height(height_), width(width_), last(height*width), field(height, vector<int>(width, 0)){
		int numeros = 1;
		for (int i = 0; i < height; ++i){
			for (int j = 0; j < width; ++j){
				field[i][j] = numeros++;
			}
		}
	}
	void move(int i, int j){
		if (i + 1 < height && field[i + 1][j] == last){
			field[i + 1][j] = field[i][j];
			field[i][j] = last;
		}
		else {
			if (i - 1 >= 0 && field[i - 1][j] == last){
				field[i - 1][j] = field[i][j];
				field[i][j] = last;
			}
			else {
				if (j + 1 < width && field[i][j + 1] == last){
					field[i][j + 1] = field[i][j];
					field[i][j] = last;
				}
				else {
					if (j - 1 >= 0 && field[i][j - 1] == last){
						field[i][j - 1] = field[i][j];
						field[i][j] = last;
					}
				}
			}
		}
	}
	BOOL win(){
		for (int i = 0; i < height; ++i){
			for (int j = 0; j < width - 1; ++j){
				if (field[i][j + 1] - field[i][j] != 1) return FALSE;
			}
		}
		return TRUE;
	}
	const size_t height, width, last;//длина высота и последний элемент массива, который по цифровому значению равен площади квадрата
	vector<vector<int> > field;
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(0);
	hInst = hInstance;
	// создаём главное окно приложения на основе модального диалога
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}
Model* game;

struct coo{
	size_t row, col;
};

map<HWND, coo> buttons;
map<HWND, coo> ::iterator it;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_INITDIALOG:{
		game = new Model(4, 4);
		//SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 200 /*width*/, 200 /*height*/, SWP_NOMOVE);
		HMENU MainMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, MainMenu);
		//создаём статик с помощью CreateWindowEx
		for (int i = 0; i < game->height; ++i)
		{
			for (int j = 0; j < game->width; ++j)
			{
				HWND hButton = CreateWindowEx(0, TEXT("BUTTON"), 0,
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0);
				buttons[hButton] = coo{ i, j };
				LEFT += 50;

				wsprintf(szText, TEXT("%d"), game->field[i][j]);
				if (game->field[i][j] == game->last) EnableWindow(hButton, 0);
				else SetWindowText(hButton, szText);
			}
			LEFT = 0;
			TOP += 50;
		}

	} return TRUE;

	case WM_CLOSE:{
		EndDialog(hWnd, 0); // закрываем модальный диалог
	}return TRUE;

	case WM_COMMAND:{
	case ID_EXIT:{
		int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
		if (res == IDYES) EndDialog(hWnd, 0);
	} break;
	default: {
		it = buttons.find((HWND)lParam);
		if (it != buttons.end()){
			game->move(it->second.row, it->second.col);
			/*if (game->win()){
				int res = MessageBox(0, TEXT("Победа"), TEXT("Вы победили"), MB_OK | MB_ICONINFORMATION);
				}*/
			for (it = buttons.begin(); it != buttons.end(); ++it){//перерисовываем поле
				int i = it->second.row; int j = it->second.col;
				wsprintf(szText, TEXT("%d"), game->field[i][j]);

				if (game->field[i][j] == game->last) {
					SetWindowText(it->first, NULL);
					EnableWindow(it->first, 0);
				}
				else{
					SetWindowText(it->first, szText);
					EnableWindow(it->first, 1);
				}
			}
		}
	}break;
	}return TRUE;

	}return FALSE;
}