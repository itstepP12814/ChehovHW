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

enum Route {LEFT, RIGHT, UP, DOWN };

class Snake;
class Field{
public:
	Field(int h_, int w_) :height(h_), width(w_), field(height, vector<bool>(width, false)){}
	void createApple(){
		srand(time(NULL));
		apple = { rand() % height, rand() % width };//Создали яблоко
	}
	bool getCellStatus(int i, int j){
		if (field[i][j]) return true;
		else return false;
	}
	int getHeight(){
		return height;
	}
	int getWidth(){
		return width;
	}
	friend Snake;
private:
	int height, width;
	Cell apple;
	vector<vector<bool>> field;
};

class Snake{
public:
	Snake(Field &Field_, int len_, int y_, int x_) : snake(len_, Cell{ 0, 0 }), route(RIGHT), F(Field_), snake_speed(150){
		for (vector<Cell>::iterator i = snake.begin(); i != snake.end(); ++i){
			i->y = y_++;
			i->x = x_;
		}
	}

	bool setPos(){
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
	int getSpeed(){
		return snake_speed;
	}
	Route getRoute(){
		return route;
	}
private:
	int snake_speed;//скорость, поеределяет время работы ф-ции таймера
	Route route;//направление
	vector<Cell> snake;//вектор с координатами ячеек, принадлежащих змейке
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

	for (int i = 0; i < F.getHeight(); ++i){//отрисовка точек поля
		for (int j = 0; j < F.getWidth(); ++j){
			if (F.getCellStatus(i, j)){
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
	if (!S.setPos()){
		MessageBox(NULL, TEXT("Корч :("), TEXT("Snake"), MB_OK);
		exit(0);
	}
	display();

	switch (S.getRoute()){
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

	if (GetAsyncKeyState(VK_LEFT) && S.getRoute() != RIGHT) S.moveLeft();
	if (GetAsyncKeyState(VK_RIGHT) && S.getRoute() != LEFT) S.moveRight();
	if (GetAsyncKeyState(VK_UP) && S.getRoute() != DOWN) S.moveUp();
	if (GetAsyncKeyState(VK_DOWN) && S.getRoute() != UP) S.moveDown();
	if (GetAsyncKeyState(27)) exit(0);

	glutTimerFunc(S.getSpeed(), timer, 0);
}

void init(){
	S.setPos();
	display();
	F.createApple();
	timer();
}

int main(int argc, char **argv){
	HWND hConsole = GetConsoleWindow();//скрываем консоль
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