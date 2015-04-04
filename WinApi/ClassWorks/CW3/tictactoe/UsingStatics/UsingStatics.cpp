#include <windows.h>
#include <vector>
#include <map>
#include <tchar.h>
#include <cstdlib>
#include "resource.h"
#include <string>

using namespace std;
/*
1 определить геймофер и кто выиграл
2 добавить кнопку новая игра
3 добавить переключатель человек-человек
человек-комп
4 опционально запрограммировать нарандомный ИИ
*/
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hButton;
TCHAR szCoordinates[20];
HINSTANCE hInst;
int LEFT = 0, TOP = 0, WIDTH = 50, HEIGHT = 50;

enum Figure { Empty, Krestik, Nolik };

class Model {

public:
	const size_t height, width;
	vector<vector<Figure> > field;
	Figure win;
	Figure move;
	bool gameover;
public:
	Model(size_t height_, size_t width_)
		:
		height(height_), width(width_),
		field(height, vector<Figure>(width, Empty)),
		win(Empty), move(Krestik),
		gameover(false)
	{
	}
	bool makemove(size_t row, size_t col) {
		if (field[row][col] == Empty) {
			field[row][col] = move;
			if (move == Krestik) {
				move = Nolik;
			}
			else {
				move = Krestik;
			}

			/// GAMEOVER?
			/// WHO WINS?
			compare();
		}
		return false;
	}
	void compare(){//проверка на выгрышные позиции
		if (!win){
			int num = 0;
			for (size_t i = 0; i < height; ++i){
				for (size_t j = 0; j < width; ++j){
					if (field[i][j]) ++num;
				}
			}
			if (num == (height*width)) {
				gameover = true;
				return;
			}
		}

		for (size_t j = 0; j < width; ++j){//проверяем строки
			if (field[j][0] == field[j][1] && field[j][1] == field[j][2]){
				if (field[j][0] != Empty){
					win = field[j][0];
					return;
				}
			}
		}
		for (size_t i = 0; i < height; ++i){
			if (field[0][i] == field[1][i] && field[1][i] == field[2][i]){
				if (field[0][i] != Empty){
					win = field[0][i];
					return;
				}
			}
		}
		if (field[0][0] != Empty && field[0][0] == field[1][1] && field[1][1] == field[2][2]) win = field[0][0];
		if (field[0][2] != Empty && field[0][2] == field[1][1] && field[1][1] == field[0][2]) win = field[0][2];
	}
};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(0);
	hInst = hInstance;
	// создаём главное окно приложения на основе модального диалога
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

struct coo {
	size_t row, col;
};

map<HWND, coo> buttons;
map<HWND, coo> ::iterator it;

Model* game;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	switch (message)
	{
	case WM_COMMAND: {
		switch (wParam){
			//////// NEW GAME
		case ID_NEWGAME:{
			delete game;
			game = new Model(3, 3);
			for (auto p : buttons) {
				SetWindowText(p.first, NULL);
			}
		} break;
		case ID_EXIT: {
			int res = MessageBox(0, TEXT("Вы уверены?"), TEXT("Выход?"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) EndDialog(hWnd, 0);
		} break;
		default: {
			it = buttons.find((HWND)lParam);
			int i = it->second.row;
			int j = it->second.col;
			game->makemove(i, j);
			/// VIEW
			for (auto p : buttons) {
				i = p.second.row;
				j = p.second.col;

				switch (game->field[i][j]) {
				case Krestik:
					SetWindowText(p.first, TEXT("X"));
					break;
				case Nolik:
					SetWindowText(p.first, TEXT("O"));
					break;
				}
			}
			/// END VIEW
			if (game->gameover) MessageBox(hWnd, TEXT("GAMEOVER"), TEXT("GAMEOVER"), MB_OK);
			if (game->win){
				TCHAR szText[30] = { 0 };
				if (game->win == Krestik) wsprintf(szText, TEXT("Победили X"));
				else wsprintf(szText, TEXT("Победили O"));
				MessageBox(hWnd, szText, TEXT("Победа"), MB_OK);
			}
			/// если теперь ход компьютера  - сделать ход
			/// мы только вычисляем на какую кнопку нажмёт компьютер
			/// отправляем сами себе сообщение о нажатии кнопки
		} break;
		}
	}return TRUE;
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
		// WM_INITDIALOG - данное сообщение приходит после создания диалогового окна, но перед его отображением на экран
	case WM_INITDIALOG:	{
		game = new Model(3, 3);
		SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 517 /*width*/, 540 /*height*/, SWP_NOMOVE);
		HMENU MainMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, MainMenu);
		//создаём статик с помощью CreateWindowEx
		for (int ico = 0; ico < 3; ico++)
		{
			for (int jco = 0; jco < 3; jco++)
			{
				buttons[CreateWindowEx(0, TEXT("BUTTON"), 0,
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					LEFT, TOP, WIDTH, HEIGHT, hWnd, 0, hInst, 0)

				] = coo{ ico, jco };
				LEFT += 50;
			}
			LEFT = 0;
			TOP += 50;
		}
	} return TRUE;
	case WM_MOUSEMOVE:
		wsprintf(szCoordinates, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // текущие координаты курсора мыши
		//	SetWindowText(hStatic1, szCoordinates);	// строка выводится на статик
		return TRUE;
	case WM_LBUTTONDOWN:
		//		SetWindowText(hStatic2, TEXT("Нажата левая кнопка мыши"));
		return TRUE;
	case WM_RBUTTONDOWN:
		//	SetWindowText(hStatic2, TEXT("Нажата правая кнопка мыши"));
		return TRUE;
	}
	return FALSE;
}
