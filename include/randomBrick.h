#ifndef RANDOM_BRICK_H
#define RANDOM_BRICK_H

#include "utils.h"
#include "segment.h"
#include <vector>

class Snake;

class RandomBrick {
private:
      std::vector<Segment> brick;
      char symbol;

public:
      RandomBrick();

      void generateRandomBrick(const Snake& snake, int width, int height);
      bool hasBrick(int x, int y);
      int getRemainingBricks() const;
      void draw() const;
};

#endif