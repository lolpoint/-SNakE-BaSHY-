CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
TARGET = pong.exe
	
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include

SRCS = src/food.cpp              \
	 src/game.cpp              \
	 src/main.cpp              \
	 src/randomBrick.cpp       \
	 src/segment.cpp           \
	 src/snake.cpp             \
	 src/utils.cpp             \
	 src/recordScoreByName.cpp \
	 src/manageScore.cpp

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m 

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "$(GREEN) ========================================= $(NC)"
	@echo ✓ Game compiled successfully!
	@echo ✓ For run game type: .\$(TARGET)
	@echo "$(GREEN) ========================================= $(NC)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

run: $(TARGET)
	@echo "$(GREEN) Running game...  $(NC)"
	.\$(TARGET)

clean:
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	if exist $(TARGET) del $(TARGET)
	@echo "$(RED) memory file is clear! $(NC)"

clean-all: clean
	if exist data\*.txt del /q data\*.txt
	@echo "$(RED)Everything cleared! $(NC)"

help:
	@echo "$(GREEN) ===============================================  $(NC)"
	@echo "$(GREEN)         Game Pong - helper Makefile              $(NC)"
	@echo "$(GREEN) ===============================================  $(NC)"
	@echo "$(GREEN)  mingw32-make            - Compile game          $(NC)"
	@echo "$(GREEN)  mingw32-make run        - Compile and run       $(NC)"
	@echo "$(GREEN)  mingw32-make clean      - Clean object files    $(NC)"
	@echo "$(GREEN)  mingw32-make clean-all  - Clean everything      $(NC)"
	@echo "$(GREEN)  mingw32-make help       - Show this help        $(NC)"
	@echo "$(GREEN) ===============================================  $(NC)"

.PHONY: all run clean clean-all help