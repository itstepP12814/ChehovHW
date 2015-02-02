#pragma once
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <exception>
#include <io.h>
#include <string>
#include <fstream>
using namespace std;

void moveAllFiles(string, string);
void copyAllFiles(string, string);
int answer(const _finddata_t*);
