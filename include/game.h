#ifndef  GAME_H
#define GAME_H

#include "manageScore.h"
#include "snake.h"
#include "segment.h"
#include "food.h"

class Game{
private:

      RandomBrick* brick;
      Food* food;
      Snake* snake;
      RecordScore* recordScore;
      ManageScore* manageScore;
      int score, width, height;
      short health;
      bool isRunning;
      int speedMoveSnake, lastScoreForSpeed;
      std::string playerName;

      void handleInput();
      void update();
      void render();
      void checkCollisions();
      void showMenu();
      int getMenuChoice();
      void getNamePlayer();
      void helper() const;
      void buildWall() const;
      void resetGame();

public:
      Game(int width, int height);
      ~Game();

      void run();
      void gameOver();
};

#endif