#define FOOD_H
#ifdef  FOOD_H

#include "utils.h"
#include "snake.h"

class Food{
private:
      int x,y;
      char symbol;
public:
      Food(int, int);
      void generateRandom(const Snake&, int, int);
      int getX() const;
      int getY() const;
      void draw() const;
};

#endif