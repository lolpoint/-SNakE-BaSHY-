#define RECORED_SCORE_BY_NAME_H
#ifdef  RECORED_SCORE_BY_NAME_H

#include <string>

class RecordScore{
private:
      std::string playerName;
      int score;

      public:
      RecordScore(std::string, int);
      
      void setterPlayerName(std::string);
      void setterScore(int);
      void display();
      int getterScore()const;
      std::string getterPlaterName()const;
      std::string toFileScore()const;
};

#endif