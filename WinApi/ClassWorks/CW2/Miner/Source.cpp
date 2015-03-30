#include <windowsx.h>
#include <Windows.h>
#include <vector>
#include <map>
#include <tchar.h>
#include <cstdlib>
#include "resource.h"
using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szCoordinates[20];
TCHAR szText[2];
HINSTANCE hInst;
const int LEFT = 35, TOP = 35, WIDTH = 30, HEIGHT = 30;//размеры поля в пикселях
const int height = 10, width = 10, mines = 10;//размеры поля в (ячейках)

class Model {

public:
	const size_t height, width, nmines;
	vector<vector<bool> > mines;
	vector<vector<bool> > isopen;
	vector<vector<int> > neighbours;
	int opened;
	bool gameover;
	bool win;
public:
	Model(size_t height_, size_t width_, size_t nmines_)
		:
		height(height_), width(width_), nmines(nmines_),
		mines(height, vector<bool>(width, false)),
		isopen(height, vector<bool>(width, false)),
		neighbours(height, vector<int>(width, 0)),
		win(false), gameover(false), opened(0)

	{
		for (size_t i = 0; i <= nmines; i++) {// расставляем рандомно мины
			mines[rand() % height][rand() % width] = true;
		}
		for (size_t row = 0; row < height; row++)//расставляем числа для соседей в пределах +-1клетки
		{
			for (size_t col = 0; col < width; col++) {
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						if ((row + i >= 0) && (row + i < height) && (col + j >= 0) && (col + j < width))//исправил (col + j < height) на (col + j < width)
							neighbours[row][col] += (int)mines[row + i][col + j];

					}
				}

			}
		}
	}
	bool check(size_t row, size_t col) {//проверяем что в ячейке
		//если не конец игры и мы не промахнулись по массивам и ячейка не открыта
		if ((!gameover) && (row >= 0) && (row < height) && (col >= 0) && (col < width) && (!isopen[row][col])){

			if (mines[row][col] == true) {//если мина-конец игры
				gameover = true;
			}
			else {//иначе-ячейка становится открытой
				isopen[row][col] = true;
				opened++;
				if (opened + nmines == height*width) {//если открыты все незаминированные ячейки-победа
					win = true;
				}
				if (neighbours[row][col] == 0) {//рекурсивная проверка
					check(row + 1, col + 1);
					check(row + 0, col + 1);
					check(row - 1, col + 1);
					check(row + 1, col + 0);
					check(row - 1, col + 0);
					check(row + 1, col - 1);
					check(row + 0, col - 1);
					check(row - 1, col - 1);
				}
			}
		}
		return gameover;
	}
};

Model M(height, width, mines);//модель поля 10*10 с 10 минами

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(0);
	hInst = hInstance;
	// создаём главное окно приложения на основе модального диалога
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

struct coo {//координаты
	size_t row, col;
};
//дерево из кнопок содержит хвнд кнопки, и коорданиты в качестве значения, точка отсчета левый верхний угол
map<HWND, coo> buttons;

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	/// nmines m(10,10,10);

	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
	case WM_INITDIALOG:{// WM_INITDIALOG - данное сообщение приходит после создания диалогового окна, но перед его отображением на экран
		for (int i = 0; i < height; ++i){//создаем поле из кнопок 10*10
			for (int j = 0; j < width; ++j){
				buttons[CreateWindowEx(0, TEXT("button"), 0,
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					LEFT + i*WIDTH, TOP + j*HEIGHT, WIDTH, HEIGHT, hWnd, 0, hInst, 0)] = coo{ i, j };
			}
		}
		HMENU MainMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
		SetMenu(hWnd, MainMenu);

	}return TRUE;
	case WM_RBUTTONDOWN:{//не работает=(
		POINT lpPoint;
		ClientToScreen(hWnd, &lpPoint);
		HWND hButton = WindowFromPoint(lpPoint);
		map<HWND, coo>::iterator it = buttons.find(hButton);
		if (it != buttons.end()){
			wsprintf(szText, TEXT("F"));
			SetWindowText(it->first, szText);
		}
	}	return TRUE;
	case WM_COMMAND:{
		map<HWND, coo>::iterator it = buttons.find((HWND)lParam);
		//файнд возвращает итератор на найденный по индексу элемент, элемент состоит из объекта - pair у которого
		//first это хвнд, second это структура
		if (it != buttons.end()){
			if (!M.check(it->second.row, it->second.col)){
				for (auto itt : buttons){
					HWND hButton = itt.first;
					coo coord = itt.second;
					if (M.isopen[coord.row][coord.col] == true){
						wsprintf(szText, TEXT("%d"), M.neighbours[coord.row][coord.col]);
						SetWindowText(hButton, szText);
					}
				}
			}
			else {
				for (auto itt : buttons){
					HWND hButton = itt.first;
					coo coord = itt.second;
					if (M.mines[coord.row][coord.col] == true){
						wsprintf(szText, TEXT("X"));
						SetWindowText(hButton, szText);
					}
					EnableWindow(hButton, 0);
				}
				MessageBox(0, TEXT("Попробуйте еще раз"), TEXT("Проиграли"), MB_OK | MB_ICONINFORMATION);
			}
		}
		switch (wParam){
		case ID_NEWGAME:{
			//возвращаем данные в первозданный вид, размеры массивов и количество мин пока не трогаем
			M.win = false; M.gameover = false; M.opened = 0;
			for (size_t i = 0; i < M.height; ++i){
				for (size_t j = 0; j < M.width; ++j){
					M.isopen[i][j] = false;
					//M.mines[i][j] = false;
					M.neighbours[i][j] = 0;
				}
			}
			for (size_t i = 0; i <= M.nmines; i++) {// расставляем рандомно мины
				//M.mines[rand() % height][rand() % width] = true;
			}
			for (size_t row = 0; row < M.height; row++)//расставляем числа для соседей в пределах +-1клетки
			{
				for (size_t col = 0; col < M.width; col++) {
					for (int i = -1; i <= 1; i++) {
						for (int j = -1; j <= 1; j++) {
							if ((row + i >= 0) && (row + i < height) && (col + j >= 0) && (col + j < width))//исправил (col + j < height) на (col + j < width)
								M.neighbours[row][col] += (int)M.mines[row + i][col + j];

						}
					}

				}
			}
			for (auto itt : buttons){//очищаем кнопки
				HWND hButton = itt.first;
				SetWindowText(hButton, 0);
				EnableWindow(hButton, 1);
			}

		} break;
		case ID_EXIT:{
			int res = MessageBox(0, TEXT("Вы уверены"), TEXT("Выход"), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) EndDialog(hWnd, 0);
		}	break;
		}
	} return TRUE;
	}

	return FALSE;
}