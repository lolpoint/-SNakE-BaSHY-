#include "..\include\recordScoreByName.h"
#include <iostream>
#include <fstream>

RecordScore::RecordScore(std::string playerName, int score){
      setterPlayerName(playerName);
      setterScore(score);
      muchTry = 1;
}

int RecordScore::getterScore()const{ return score; }
std::string RecordScore::getterPlayerName()const{ return playerName; }
void RecordScore::setterMuchTry(int much_try){ this->muchTry = much_try; }

void RecordScore::setterPlayerName(std::string playerName){
      try{
            this->playerName = playerName;
            if(this->playerName == ""){
                  throw std::runtime_error("have't name for save record...");
            }
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
      }
}

void RecordScore::setterScore(int score){
      try{
            this->score = score;
            if(this->score < 0){
                  throw std::runtime_error("have't score for save record...");
            }
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
      }
}

void RecordScore::display() const{
      std:: cout << playerName << " | " << score << '\n';
}

std::string RecordScore::toFileScore() const{

      std::string muchTryToGame;
      if(muchTry == 1){
            muchTryToGame = "ONE TRY";
      }else{
            muchTryToGame = std::to_string(muchTry);
      }
      std::string scoreStr = std::to_string(score);
      int totalLength = 25 - playerName.length() - scoreStr.length();
      if(totalLength < 0) totalLength = 1;
      std::string underLine(totalLength, '-');

      return playerName + underLine + scoreStr + " (" + muchTryToGame + ")";
}

void RecordScore::oneIncreasTry(){
      muchTry++;
}
int RecordScore::getterMuchTry() const{
      return muchTry;
}