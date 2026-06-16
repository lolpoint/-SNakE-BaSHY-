#ifndef  UTILS_H
#define UTILS_H

#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

void gotoXY(int, int);

void hideCursor();

void highlightText(std::string, int, int, int);
void loadSimilaitor(int, int, int, int);

enum Dir{ UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

#endif