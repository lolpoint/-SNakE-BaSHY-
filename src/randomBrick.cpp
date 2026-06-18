#include "../include/randomBrick.h"
#include "../include/snake.h" 
#include "../include/segment.h" 
#include "../include/utils.h"
#include <iostream>
#include <random>
#include <chrono>

RandomBrick::RandomBrick() {
      this->symbol = '#';
      brick.clear();
}

bool RandomBrick::hasBrick(int x ,int y){
      for(const auto& bricks : brick){
            if(bricks.getX() == x && bricks.getY() == y){
                  return true;
            }
      }
      return false;
}

void RandomBrick::generateRandomBrick(const Snake& snake, int width, int height) {
      brick.clear();

      std::mt19937 pesudo{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
      std::uniform_int_distribution width_brick{1, width - 1};
      std::uniform_int_distribution height_brick{1, height - 1};
      std::uniform_int_distribution digit_generate{10, 20};

      const std::vector<Segment> body = snake.getBody();
      int count = digit_generate(pesudo);
      
      for (int G = 0; G < count; G++) {
            int x = width_brick(pesudo);
            int y = height_brick(pesudo);

            bool onSnake = false;
            for (const auto& segment : body) {
                  if (segment.getX() == x && segment.getY() == y) {
                        onSnake = true;
                        break;
                  }
            }

            bool duplicate = false;
            for (const auto& bricks : brick) {
                  if (bricks.getX() == x && bricks.getY() == y) {
                      duplicate = true;
                      break;
                  }
            }

            if(!duplicate && !onSnake){
                  brick.push_back(Segment(x, y));
            }
      }
}

void RandomBrick::draw() const {
      for (const auto& bricks : brick) {
            gotoXY(bricks.getX(), bricks.getY());
            std::cout << symbol;
      } 
}

int RandomBrick::getRemainingBricks() const {
      return brick.size();
}