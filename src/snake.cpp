#include "../include/snake.h"
#include <iostream>

Snake::Snake(Dir dir, Dir oldDir, int initialLenght){
      this->direction = dir;
      this->oldDirection = oldDir;
      this->initialLenght = initialLenght;
      setSnakeHead('^');
      setSnakeBody('*');
      setBody();
}

void Snake::setBody(){
      int startX = 20;
      int startY = 10;
      short _i = 0;
      short _j = 0;
      short _k = 0;

      for(int i = _i; i < initialLenght; i++){
            body.push_back(Segment(startX - i, startY));
            _i++;
      }
}

void Snake::move(){
      int newX = body[0].getX();
      int newY = body[0].getY();

      switch(direction){
            case 0: { newY--; setSnakeHead('^'); break; }
            case 1: { newX++; setSnakeHead('>'); break; }
            case 2: { newY++; setSnakeHead('v'); break; }
            case 3: { newX--; setSnakeHead('<'); break; }
      }

      body.insert(body.begin(), Segment(newX, newY));
      body.pop_back();
      oldDirection = direction;
}

void Snake::grow(){
      int tailX = body.back().getX();
      int tailY = body.back().getY();
      body.push_back(Segment(tailX, tailY));
}

void Snake::draw() const{
      for(size_t i = 0; i < body.size(); i++) {
            gotoXY(body[i].getX(), body[i].getY());
            if(i == 0) {
                  std::cout << snakeHead;
            } else {
                  std::cout << snakeBody;  
            }
      }
}

void Snake::erase() const{
      for(const auto& segment : body) {
            gotoXY(segment.getX(), segment.getY());
            std::cout << ' ';
      }
}
      
void Snake::changeDirection(Dir newDir){
      if((direction == UP && newDir == DOWN)
            || (direction == RIGHT && newDir == LEFT)
            || (direction == LEFT && newDir == RIGHT)
            || (direction == DOWN && newDir == UP)){
                  return;
            }
      oldDirection = direction;
      direction = newDir;
}

bool Snake::checkSelfCollsion() const{
      for(size_t i = 1; i < body.size(); i++){
            if(body[0].getX() == body[i].getX()
            && body[0].getY() == body[i].getY()){
                  return true;
            }
      }
      return false;
}

bool Snake::checkWallCollsoin(int width, int height) const{
      int headX = body[0].getX();
      int headY = body[0].getY();
    
      return (headX <= 0 || headX >= width || headY <= 0 || headY >= height);
}

void Snake::setDefaultBody(){
      this->direction = UP;
      this->oldDirection = UP;
      this->initialLenght = 4;
      setBody();
}
      
const std::vector<Segment>& Snake::getBody() const{ return body; }
int Snake::getDirection() const{ return direction; }
int Snake::getInitialLenght() const{ return initialLenght; }
void Snake::setOldDirection(Dir dir){ this->oldDirection = dir; }
void Snake::setSnakeHead(char snakeHead){ this->snakeHead = snakeHead; }
void Snake::setSnakeBody(char snakeBody){ this->snakeBody = snakeBody; }