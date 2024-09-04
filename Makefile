CXX := g++
CXXFLAGS := -std=c++11 -I/opt/homebrew/include/SDL2 -Igame -I src/include
LDFLAGS := -L/opt/homebrew/lib
LIBS := -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lncurses

SRC_DIR := game
SRC_FILE := src
GRAPHIC_DIR := $(SRC_DIR)/graphic_game/CPP_files
LOGIC_DIR := $(SRC_DIR)/logic_game/CPP_files
OBJ_DIR := $(SRC_FILE)/obj

SRC_FILES := main.cpp \
	$(LOGIC_DIR)/Board.cpp \
	$(LOGIC_DIR)/Tiles.cpp \
	$(LOGIC_DIR)/Game.cpp \
	$(LOGIC_DIR)/Input.cpp \
	$(GRAPHIC_DIR)/Window.cpp \
	$(LOGIC_DIR)/BoardSdl.cpp \
	$(GRAPHIC_DIR)/GameObject.cpp

# Convert source file paths to object file paths in the obj directory
OBJ_FILES := $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

TARGET := main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

# Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
