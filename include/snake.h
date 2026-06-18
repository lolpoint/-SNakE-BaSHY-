#ifndef  SNAKE_H
#define SNAKE_H

#include "utils.h"
#include "segment.h"
#include "randomBrick.h"
#include <vector>

class RandomBrick;

class Snake
{
private:
      std::vector<Segment> body;
      Dir direction;
      Dir oldDirection;
      char snakeHead, snakeBody;
      int initialLenght;

      public:
      Snake(Dir, Dir, int);
      
      void setBody();
      void move();
      void grow();
      void draw() const;
      void erase() const;

      void changeDirection(Dir);
      bool checkSelfCollsion() const;
      bool checkWallCollsoin(int, int) const;
      
      const std::vector<Segment>& getBody() const;
      int getDirection() const;
      int getInitialLenght() const;
      void setOldDirection(Dir);
      void setSnakeHead(char);
      void setSnakeBody(char);
      void setDefaultBody();

};

#endif