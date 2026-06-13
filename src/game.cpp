#define GAME_H
#ifdef  GAME_H

#include "manageScore.h"

class Game{
private:

      RecordScore* recordScore;
      ManageScore* manageScore;
      int score, width, height;
      short health;
      bool isRunning;
      int lastScoreForSpeed;
      std::string playerName;

      void handleInput();
      void update();
      void render();
      void checkCollisions();
      void showMenu();
      int getMenuChoice();
      void getNamePlayer();

public:
      Game(int width, int height);
      ~Game();

      void run();
      void gameOver();
};

#endif