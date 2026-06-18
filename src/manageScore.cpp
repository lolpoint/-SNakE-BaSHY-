
#include "..\include\manageScore.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


std::string ManageScore::getterFileName()const{ return fileName; }

bool ManageScore::saveScore(){
      try{
            size_t indexLayer = 0;
            std::ofstream file(fileName);
            if(!file.is_open()) throw std::runtime_error("Cannot open file: " + fileName);
            for(const auto& record : recordScore){
                  file << record.toFileScore() << '\n';
            }
            file.close();
            return true;
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
            return false;
      }
}

void ManageScore::sortByScore(bool ascending){
      try{
            if(recordScore.empty()) throw std::runtime_error("not exist Score...");
            if(ascending){
                  std::sort(recordScore.begin(), recordScore.end(),[](const RecordScore& a, const RecordScore& b) {
                              return a.getterScore() < b.getterScore();
                        }
                  );
                  std::cout << "List sorted by Score(Low to High)!\n"; 
            }else{
                  std::sort(recordScore.begin(), recordScore.end(),[](const RecordScore& a, const RecordScore& b) {
                              return a.getterScore() > b.getterScore();
                        }
                  );
                  std::cout << "List sorted by Score(High to Low)!\n"; 
            }
            saveScore();
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
      }
}

void ManageScore::addScoreWithName(RecordScore& record){
      try{
            if(hasPlayerName(record.getterPlayerName())){
                  hasPlayerNameChange(record.getterPlayerName(), record.getterScore());
            }
            else recordScore.push_back(record);

            if(hasPlayerName(record.getterPlayerName()) && record.getterPlayerName() == "Anonymous"){
                  std::string newName = "Anonymous" + std::to_string(countAnonymous);
                  record.setterPlayerName(newName);
                  countAnonymous++;
            }     

            if(!saveScore()) {  
                  throw std::runtime_error("Failed to save score to file");
            }
            std::cout << "!!!Score added!!!" <<'\n';
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
      }
}

void ManageScore::showTopTenScoreRecord(){
      try{
            loadFromFile(fileName);

            std::cout << "\n=== SCORE LIST ===\n";

            if(recordScore.empty()){
                  std::cout << "No scores yet! Play the game to set a record.!\n";
                  std::cout << "==================\n";
                  throw std::runtime_error("not exist Score...");
            }

            for(size_t i = 0; i < recordScore.size(); i++){
                  std::cout << i+1 << ". ";
                  recordScore[i].display();
            }
      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << '\n';
      }
}

void ManageScore::loadFromFile(const std::string& filename){
      try{
            fileName = filename;
            std::ifstream file(filename);
            if(!file.is_open()){
                  throw std::runtime_error("Cannot open file: " + filename);
            }
            
            recordScore.clear();
            std::string line;

            while(std::getline(file, line)){
                  if(line.empty() || line[0] == '#') continue;
                  size_t pos = line.find('-');
                  if(pos != std::string::npos){
                        std::string name = line.substr(0, pos);
                        size_t scoreStart = line.find_last_of('-') + 1;
                        std::string scoreStr = line.substr(scoreStart);
                        try{
                              int score = std::stoi(scoreStr);
                              recordScore.push_back(RecordScore(name, score));
                        }catch(const std::exception& e){
                              std::cerr << "Invalid score in line: " << line << '\n';
                        }
                  }
            }
            file.close();
      }catch(const std::exception& e){
            std::cerr << "Error loading file: " << e.what() << '\n';
            std::string newFileName = "data/record.txt";

            #ifdef _WIN32
                  system("mkdir data 2>nul");
            #else
                  mkdir("data", 0777);
            #endif

            std::ofstream newFile(newFileName);
            if(newFile.is_open()) {
                  newFile << "### SNAKE GAME RECORDS ###" << '\n';
                  newFile << "### Format: NAME-SCORE ###" << '\n';
                  newFile.close();
                  std::cout << "Created default record file at: \n" << newFileName << '\n';
            
                  loadFromFile(newFileName);
            } else {
                  std::cerr << "FATAL: Cannot create file even at default path!" << '\n';
            }
      }
}

bool ManageScore::hasPlayerName(std::string player){
      size_t indexLayer = 0;
      for(const auto& searchName : recordScore){
            if(searchName.getterPlayerName() == player){
                  recordScore[indexLayer].oneIncreasTry();
                  return true;
            }
            indexLayer++;
      }
      return false;
}

void ManageScore::hasPlayerNameChange(std::string player, int score){
      for(auto& searchName : recordScore){
            if(searchName.getterPlayerName() == player){
                  if(searchName.getterScore() >= score) break;
                  searchName.setterScore(score);
                  break;
            }
      }
      saveScore();
}