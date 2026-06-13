#include "..\include\utils.h"

void gotoXY(int x, int y){
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor(){
      HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO info;
      info.dwSize = 50;
      info.bVisible = false;
      SetConsoleCursorInfo(consoleHandle, &info);
}