#ifndef  RECORED_SCORE_BY_NAME_H
#define RECORED_SCORE_BY_NAME_H

#include <string>

class RecordScore{
private:
      std::string playerName;
      int score, muchTry;

      public:
      RecordScore(std::string, int);
      
      void setterPlayerName(std::string);
      void setterScore(int);
      int getterMuchTry() const;
      std::string getterPlayerName()const;
      void setterMuchTry(int much_try);

      int getterScore()const;
      void display() const;
      std::string toFileScore()const;
      void oneIncreasTry();
};

#endif