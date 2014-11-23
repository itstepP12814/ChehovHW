#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;
enum genre {comedy, fantasy, fantastic};
enum rate {bad, norm, cool};
/*в перечислении мы указали нумерацию с единицы, т.к это важно для функции возвращения количества фильмов из базы*/
struct video
{
    char title [512];
    char direct[512];
    genre gnr;
    rate rt;
    int cost;
};
video *base();
void titleSearch(int, video *p);
void dirSearch(int, video *p);
void result(video *p);
void genreSearch(int, video *p);
void genreSort(int, video *p);
void highRate(int, video *p);
void dispAll(int, video *p);
int create(int, video *p);
void writeToBase(int, video *p);
char *getBase();
#endif // HEADER_H
