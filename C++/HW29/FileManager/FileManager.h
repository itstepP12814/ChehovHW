#pragma once
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <exception>
#include <io.h>
#include <string>
#include <fstream>
using namespace std;

void moveAllFiles(const string, const string);
void copyAllFiles(const string, const string);
void showAllFiles(string);
void copyFile(const string, const string);
void moveFile(const string, const string);
void renameFile(const string, const string);
void removeAllFiles(const string);
int answer(const _finddata_t*);
string parser(string);