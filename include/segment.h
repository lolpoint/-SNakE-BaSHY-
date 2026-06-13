#define SEGMENT_H
#ifdef  SEGMENT_H

#include "utils.h"

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