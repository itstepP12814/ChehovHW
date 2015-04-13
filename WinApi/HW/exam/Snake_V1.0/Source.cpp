#include <iostream>
#include <vector>
#include <Windows.h>
#include <tchar.h>
#include <glut.h>
#include <stdio.h>
#include <time.h>
using namespace std;

struct Cell{
	int x, y;
};

enum Route { UNDEF, LEFT, RIGHT, UP, DOWN };

class Snake;
class Field{
public:
	Field(int h_, int w_) :height(h_), width(w_), field(height, vector<bool>(width, false)){}
	void createApple(){
		srand(time(NULL));
		apple = { rand() % height, rand() % width };//Создали яблоко
	}
	int height, width;
	Cell apple;
	vector<vector<bool>> field;
};

class Snake{
public:
	Snake(Field &F_, int l_, int y_, int x_) : snake_long(l_), snake(snake_long, Cell{ 0, 0 }), route(RIGHT), F(F_), snake_speed(150){
		for (vector<Cell>::iterator i = snake.begin(); i != snake.end(); ++i){
			i->y = y_++;
			i->x = x_;
		}
	}

	bool mark(){
		for (int h = 0; h < F.height; ++h){
			for (int w = 0; w < F.width; ++w){
				F.field[h][w] = false;
			}
		}

		for (vector<Cell>::iterator i = snake.begin(); i != snake.end(); ++i){
			//блок проверки, если стукнулись в стенку - выйти с другого конца (мухаха)
			if (i->y >= F.height) i->y = 0;
			if (i->y < 0) i->y = F.height - 1;
			if (i->x >= F.width)	i->x = 0;
			if (i->x < 0)i->x = F.width - 1;

			if (F.field[i->y][i->x] == false) F.field[i->y][i->x] = true;
			else return false;
		}
		F.field[F.apple.x][F.apple.y] = true;
		return true;
	}
	bool moveRight(){
		eatApple();
		vector<Cell>::iterator head = snake.begin();
		Cell temp = *head, current;
		head->x = ++(head->x);//сдвинули голову
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			if (head == i)return false;
		}
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			current = *i;
			*i = temp;
			temp = current;
		}
		route = RIGHT;
		return true;
	}
	bool moveLeft(){
		eatApple();
		vector<Cell>::iterator head = snake.begin();
		Cell temp = *head, current;
		head->x = --(head->x);
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			if (head == i)return false;
		}
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			current = *i;
			*i = temp;
			temp = current;
		}
		route = LEFT;
		return true;
	}
	bool moveUp(){
		eatApple();
		vector<Cell>::iterator head = snake.begin();
		Cell temp = *head, current;
		head->y = ++(head->y);
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			if (head == i)return false;
		}
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			current = *i;
			*i = temp;
			temp = current;
		}
		route = UP;
		return true;
	}
	bool moveDown(){
		eatApple();
		vector<Cell>::iterator head = snake.begin();
		Cell temp = *head, current;
		head->y = --(head->y);
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			if (head == i)return false;
		}
		for (vector<Cell>::iterator i = snake.begin() + 1; i != snake.end(); ++i){
			current = *i;
			*i = temp;
			temp = current;
		}
		route = DOWN;
		return true;
	}
	void eatApple(){
		vector<Cell>::iterator head = snake.begin();
		if (head->x == F.apple.y && head->y == F.apple.x) {
			snake.push_back(F.apple);
			if (snake_speed > 10){
				snake_speed -= 10;
			}
			F.createApple();
		}
	}

	int snake_long;
	int snake_speed;
	Route route;
	vector<Cell> snake;
	Field& F;//ссылка на поле
};


Field F(35, 45);
Snake S(F, 1, 7, 8);



void display(){

	glPointSize(10);//диаметр растровой точки
	glClear(GL_COLOR_BUFFER_BIT);//очистка экрана в черный цвет
	glBegin(GL_POINTS);//начинаем рисовать точки

	glColor3f(0.5, 0.1, 0);//цвет точек
	for (int i = 20; i < 480; i++) glVertex2f(i, 20);//ставим левую стенку 380 точек
	for (int i = 20; i < 380; i++) glVertex2f(20, i);//нижнюю 280 точек
	for (int i = 20; i < 480; i++) glVertex2f(i, 380);//правую
	for (int i = 20; i < 380; i++) glVertex2f(480, i);//верхнюю

	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < F.height; ++i){//отрисовка точек поля
		for (int j = 0; j < F.width; ++j){
			if (F.field[i][j]){
				glColor3f(0, 1, 0);
				glVertex2f(j * 10 + 30, i * 10 + 30);
			}
			else {
				glColor3f(0.1, 0.1, 0);
				glVertex2f(j * 10 + 30, i * 10 + 30);
			}
		}
	}

	glClear(GL_COLOR_BUFFER_BIT);

	glEnd();
	glFlush();
	glutSwapBuffers();//смена экранных буферов
}

void timer(int = 0){
	if (!S.mark()){
		MessageBox(NULL, TEXT("Корч :("), TEXT("Snake"), MB_OK);
		exit(0);
	}
	display();

	switch (S.route){
	case LEFT:
		S.moveLeft();
		break;
	case RIGHT:
		S.moveRight();
		break;
	case UP:
		S.moveUp();
		break;
	case DOWN:
		S.moveDown();
		break;
	}

	if (GetAsyncKeyState(VK_LEFT) && S.route != RIGHT) S.moveLeft();
	if (GetAsyncKeyState(VK_RIGHT) && S.route != LEFT) S.moveRight();
	if (GetAsyncKeyState(VK_UP) && S.route != DOWN) S.moveUp();
	if (GetAsyncKeyState(VK_DOWN) && S.route != UP) S.moveDown();
	if (GetAsyncKeyState(27)) exit(0);

	glutTimerFunc(S.snake_speed, timer, 0);
}

void init(){
	S.mark();
	display();
	F.createApple();
	timer();
}

int main(int argc, char **argv){
	HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
	ShowWindow(hConsole, SW_HIDE);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Snake");
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 500, 400);
	gluOrtho2D(0.0, 500.0, 0.0, 400.0);
	glutDisplayFunc(display);

	init();

	glutMainLoop();



	return 0;
}