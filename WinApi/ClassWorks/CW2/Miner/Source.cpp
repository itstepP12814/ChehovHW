#include <windows.h>
#include <vector>
#include <map>
#include <tchar.h>
#include <cstdlib>
#include "resource.h"

using namespace std;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hStatic1, hStatic2;
TCHAR szCoordinates[20];
HINSTANCE hInst;
const int LEFT = 25, TOP = 25, WIDTH = 30, HEIGHT = 30, height = 10, width = 10;

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
		for (size_t i = 0; i < nmines; i++) {// расставляем рандомно мины
			mines[rand() % height][rand() % width] = true;
		}
		for (size_t row = 0; row < height; row++)
		{
			for (size_t col = 0; col < width; col++) {
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						if ((row + i >= 0) && (row + i < height) &&
							(col + j >= 0) && (col + j < height))
							neighbours[row][col] += (int)mines[row + i][col + j];

					}
				}

			}
		}
	}
	bool check(size_t row, size_t col) {

		if ((!gameover) && (row >= 0) && (row < height) && (col >= 0) && (col < width) && (!isopen[row][col])){

			if (mines[row][col]) {
				gameover = true;
			}
			else {
				isopen[row][col] = true;
				opened++;
				if (opened + nmines == height*width) {
					win = true;
				}
				if (neighbours[row][col] == 0) {
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

Model M(height, width, 10);

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

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	/// nmines m(10,10,10);

	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
		// WM_INITDIALOG - данное сообщение приходит после создания диалогового окна, но перед его отображением на экран
	case WM_INITDIALOG:{
		for (int i = 0; i < height; ++i){
			for (int j = 0; j < width; ++j){
				buttons[CreateWindowEx(0, TEXT("button"), 0,
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
					LEFT + i*WIDTH, TOP + j*HEIGHT, WIDTH, HEIGHT, hWnd, 0, hInst, 0)] = coo{ i, j };
			}
		}


	}return TRUE;
	case WM_MOUSEMOVE:

		return TRUE;
	case WM_LBUTTONDOWN:

		return TRUE;
	case WM_RBUTTONDOWN:

		return TRUE;
	case WM_COMMAND:{
		map<HWND, coo>::iterator it = buttons.find((HWND)lParam);
		//файнд возвращает итератор на анйденный по индексу элемент, элемент состоит из объекта - pair у которого
		//first это хвнд, секонд это структура
		M.check(it->second.row, it->second.col);
		for (auto itt : buttons){
			HWND hButton = itt.first;
			coo coord = itt.second;
			if (M.isopen[coord.row][coord.col]==true){
				SetWindowText(hButton, TEXT("P"));
			}
		}
		
	} return TRUE;
	}

	return FALSE;
}