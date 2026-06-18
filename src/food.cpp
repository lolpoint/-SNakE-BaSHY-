#include "..\include\food.h"
#include <random>
#include <chrono>
#include <iostream>

Food::Food(){
      this->symbol = 'o';
}

int Food::getX() const{ return x; }
int Food::getY() const{ return y; }

void Food::generateRandomFood(const Snake& snake, int width, int height){
      std::mt19937 pesudo{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
      std::uniform_int_distribution width_food{1, width-1};
      std::uniform_int_distribution height_food{1, height-1};
      bool validPosision = false;
      std::vector<Segment> body = snake.getBody();

      while(!validPosision){
            x = width_food(pesudo);
            y = height_food(pesudo);
            validPosision = true;

            for(const auto& segment : body){
                  if(segment.getX() == x && segment.getY() == y){
                        validPosision = false;
                        break;
                  }
            }
      }

      draw();
}


void Food::draw() const{
      gotoXY(x, y);
      std::cout << symbol;
}
