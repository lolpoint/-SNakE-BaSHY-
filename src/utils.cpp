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

void highlightText(std::string text, int loopCount, int x, int y){
      int loopTime = 200;
      while(loopCount){
            loopCount--;
            gotoXY(x, y);
            Sleep(loopTime);
            std::cout << text;
            gotoXY(x, y);
            Sleep(loopTime);
            std::string hide(text.length(), ' ');
            std::cout << hide;
      }
}

void loadSimilaitor(int time, int x, int y, int loop){
      while(loop > 0){
            gotoXY(x, y);
            std::cout << "|";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "/";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "-";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "\\";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "|";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "/";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "-";
            Sleep(time);
            gotoXY(x, y);
            std::cout << "\\";
            Sleep(time);
            loop--;
      }
}