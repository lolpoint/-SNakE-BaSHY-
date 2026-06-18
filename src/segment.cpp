#include "..\include\segment.h"

Segment::Segment(int x, int y){
      setX(x);
      setY(y);
}

int Segment::getX() const{ return x; }
int Segment::getY() const{ return y; }
void Segment::setX(int x){ this->x = x; }
void Segment::setY(int y){ this->y = y; }