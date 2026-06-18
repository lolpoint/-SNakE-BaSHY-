#ifndef  SEGMENT_H
#define SEGMENT_H

class Segment{
      private:
            int x, y;
      public:
      Segment(int, int);

      int getX() const;
      int getY() const;
      void setX(int);
      void setY(int);
};

#endif