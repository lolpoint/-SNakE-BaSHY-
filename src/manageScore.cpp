#define MANAGE_SCORE_H
#ifdef  MANAGE_SCORE_H

#include <vector>
#include "recordScoreByName.h"

class ManageScore{
private:
      std::vector <RecordScore> recordScore;
      std::string fileName = "data/record.txt";

public:
      bool saveScore();
      void sortByScore(bool = false);
      void addScoreWithName(const RecordScore&);
      void showTopTenScoreRecord();
      void loadFromFile(const std::string&);
      std::string getterFileName()const;
};

#endif