@echo off
echo===========================
echo     SNAKE BASY is compiling...
echo===========================

g++ -std=c++17 src\ball.cpp src\game.cpp src\paddle.cpp src\main.cpp src\utils.cpp src\manageScore.cpp src\recordScoreByName.cpp src\brick.cpp -o pong.exe -lwinmm

if %errorlevel% == 0 (
	echo.
	echo compiling is secsefulate
	echo for run game typr: pong.exe
) else (
	echo.
	echo error compiling
)

echo==================================