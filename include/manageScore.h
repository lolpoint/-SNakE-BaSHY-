#ifndef  MANAGE_SCORE_H
#define MANAGE_SCORE_H

#include <vector>
#include "recordScoreByName.h"

class ManageScore{
private:
      std::vector <RecordScore> recordScore;
      std::string fileName = "data/record.txt";
      int countAnonymous = 1;

public:
      bool saveScore();
      void sortByScore(bool = false);
      void addScoreWithName(RecordScore&);
      void showTopTenScoreRecord();
      void loadFromFile(const std::string&);
      bool hasPlayerName(std::string);
      void hasPlayerNameChange(std::string, int);
      
      std::string getterFileName()const;
};

#endif