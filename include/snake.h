#define SNAKE_H
#ifdef  SNAKE_H

#include "segment.h"
#include "utils.h"
#include <vector>

class Snake
{
private:
      enum Dir{ UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };
      std::vector<Segment> body;
      Dir direction;
      Dir oldDirection;
      char snakeHead, snakeBody;
      int initialLenght;

      void setBody();
public:
      Snake(Dir, Dir, int);

      void move();
      void grow();
      void draw() const;
      void erase() const;

      void changeDirection(Dir);
      bool checkSelfCollsion() const;
      bool checkWallCollsoin(int, int) const;
      
      std::vector<Segment> getBody() const;
      int getDirection() const;
      void setOldDirection(Dir);
      void setSnakeHead(char);
      void setSnakeBody(char);

};

#endif