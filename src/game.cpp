#include "../include/game.h"
#include "../include/utils.h"
#include <conio.h>
#include <iostream>

Game::Game(int width, int height){
      this->width = width;
      this->height = height;
      snake = new Snake(UP, UP, 3);
      food = new Food();
      food->generateRandomFood(*snake, width, height);
      recordScore = new RecordScore("", 0);
      manageScore = new ManageScore();
      score = 0;
      health = 3;
      isRunning = true;
      speedMoveSnake = 150;
      playerName = "";
      lastScoreForSpeed = 0;
}

Game::~Game(){
      delete snake;
      delete food;
      delete recordScore;
      delete manageScore;
}

void Game::handleInput(){
      if(_kbhit()){
            char keyHit = _getch();
            if(keyHit == 'a' || keyHit == 'A'){
                  snake->changeDirection(LEFT);
            }
            else if(keyHit == 's' || keyHit == 'S'){
                  snake->changeDirection(DOWN);
            }
            else if(keyHit == 'd' || keyHit == 'D'){
                  snake->changeDirection(RIGHT);
            }
            else if(keyHit == 'w' || keyHit == 'W'){
                  snake->changeDirection(UP);
            }else if(keyHit == 27){
                  isRunning =false;
            }
      }
}

void Game::run(){
      hideCursor();
      showMenu();

      HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
      int choice = getMenuChoice();      
 
      if(choice == 4){
            system("cls");
            gotoXY(width/2, height/2);
            std::cout << "Goodbye!" << '\n';
            return;
      }

      else if(choice == 3){
            system("cls");
            manageScore->showTopTenScoreRecord();
            gotoXY(0, 25);
            std::cout << "Press any key to return to menu...";
            _getch();
            run(); 
            return;
      }
      
      else if(choice == 2){
            helper();
            run();
      }
      
      else if(choice == 1){
            getNamePlayer();

            buildWall();
            while(isRunning){
                  buildWall();
                  handleInput();
                  update();
                  checkCollisions();
                  render();
                  Sleep(speedMoveSnake);
            }
            gameOver();

            gotoXY(width/2, height/2 + 6);
            std::cout << "Press any key return menu...";
            _kbhit();
            run();
      }
}

void Game::update(){
      snake->move();
}

void Game::render(){
      HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
      const std::vector<Segment>& getBodySegment = snake->getBody();

      system("cls");
      buildWall();

      if(!getBodySegment.empty()){
            gotoXY(width + 2, 2);
            std::cout << "Snake Head POS(x,y): (" << getBodySegment[0].getX() << "," << getBodySegment[0].getY() << ")";
      } 
      gotoXY(width + 3, 4);
      std::cout << "Health: " << health;
      gotoXY(width + 3, 5);
      std::cout << "Player: " << playerName;
      gotoXY(width + 3, 6);
      std::cout << "Score: " << score;
      gotoXY(width + 3, 8);
      std::cout << "Snake Body length: " << getBodySegment.size();

      if(recordScore->getterMuchTry() > 1){
            gotoXY(width + 2, 7);
            std::cout << "Last score: " << recordScore->getterMuchTry();
      }

      SetConsoleTextAttribute(Hconsole, 4);
      food->draw();

      SetConsoleTextAttribute(Hconsole, 2);
      snake->draw();

      SetConsoleTextAttribute(Hconsole, 7);
}

void Game::buildWall() const{
      for(int w = 0; w <= width; w++){
            gotoXY(w, 0);
            std::cout << "#";
            gotoXY(w, height);
            std::cout << "#";
      }
      for(int h = 0; h <= height; h++){
            gotoXY(0, h);
            std::cout << "#";
            gotoXY(width, h);
            std::cout << "#";
      }
}

void Game::showMenu(){
      system("cls");
      gotoXY(width/2 - 8, height/2 - 2);
      std::cout << "=== SNAKE GAME ===";
      gotoXY(width/2 - 8, height/2);
      std::cout << "1. Start Game";
      gotoXY(width/2 - 8, height/2 + 1);
      std::cout << "2. How to Play";
      gotoXY(width/2 - 8, height/2 + 2);
      std::cout << "3. Show Top Teen score";
      gotoXY(width/2 - 8, height/2 + 3);
      std::cout << "4. Exit";
      gotoXY(width/2 - 12, height/2 + 5);
      std::cout << "Use 1, 2, 3, 4 to select";
}

int Game::getMenuChoice(){
      
      while(true){
            if(_kbhit()){
                  char choice = _getch();
                  if(choice == '1') return 1;
                  if(choice == '2') return 2;
                  if(choice == '3') return 3;
                  if(choice == '4') return 4;
                  
                  HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
                  SetConsoleTextAttribute(Hconsole, 4);
                  gotoXY(width/2 - 10, height/2 - 5);
                  std::cout << "!!! Invalid choice! Press 1,2,3,4 !!!";
                  Sleep(500);
                  gotoXY(width/2 - 10, height/2 - 5);
                  std::cout << "                                     ";

                  SetConsoleTextAttribute(Hconsole, 7);
                  
            }
            Sleep(50);
      }
}

void Game::getNamePlayer(){
      system("cls");
      gotoXY(width/2 - 24, height/2);
      std::cout << "Enter your name or nickname for save record..."; 
      gotoXY(width/2, height/2 + 1);
      std::getline(std::cin, playerName);
      recordScore->setterPlayerName(playerName);
      if(playerName == "") {
            playerName = "Anonymous";
            recordScore->setterPlayerName(playerName);
      }
}

void Game::gameOver(){
      system("cls");
      gotoXY(width/2, height/2);
      std::cout << "GAME OVER!";
      gotoXY(width/2, height/2 + 1);
      std::cout << "Final Score: " << score;
      gotoXY(width/2, height/2 + 2);

      try{
            manageScore->loadFromFile(manageScore->getterFileName());
            recordScore->setterScore(score);
            manageScore->addScoreWithName(*recordScore);
            manageScore->sortByScore(false);
            recordScore->display();
            loadSimilaitor(100, width/2, height/2 + 4, 2);
            gotoXY(width/2, height/2 + 4);
            std::cout << "Score saved temporarily!";

      }catch(const std::exception& e){
            std::cerr << "Error: " << e.what();
      }
}

void Game::helper() const{
      system("cls");
      gotoXY(width/2 - 15, height/2 - 2);
      std::cout << "=== HOW TO PLAY ===";
      gotoXY(width/2 - 18, height/2);
      std::cout << "Play with W/A/S/D for move Snake";
      gotoXY(width/2 - 15, height/2 + 1);
      std::cout << "Eat Apple and do best score in this game";
      gotoXY(width/2 - 18, height/2 + 2);
      std::cout << "ESC: Exit game";
      gotoXY(width/2 - 15, height/2 + 4);
      std::cout << "Press any key to start...";
      _getch();
}

void Game::checkCollisions(){
      HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
      const std::vector<Segment>& getBodySegment = snake->getBody();
      
      if(food->getX() == getBodySegment[0].getX() && food->getY() == getBodySegment[0].getY()){
            score += 10;
            snake->grow();
            food->generateRandomFood(*snake, width, height);
      }

      if(snake->checkSelfCollsion()
      || snake->checkWallCollsoin(width, height)){  

            if(health > 0){
                  health--;
            }else{ 
                  isRunning = false;
            }   
            int lenght = getBodySegment.size();
            delete snake;
            snake = new Snake(UP, UP, lenght);
            loadSimilaitor(100, width/2, height/2, 1);
      }

      if(score >= 100 && score / 100 > lastScoreForSpeed){
            lastScoreForSpeed = score / 100;
            gotoXY(width/2, height/2);
            SetConsoleTextAttribute(Hconsole, 6);
            highlightText("^^LEVEL UP^^", 5, width/2-3, height/2);
            speedMoveSnake -= 10;
            SetConsoleTextAttribute(Hconsole, 7);
      }

      if(snake->getDirection() == UP || snake->getDirection() == DOWN){
            Sleep(50);
      }
}