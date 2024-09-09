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
	$(GRAPHIC_DIR)/GridSdl.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/WindowSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/GridSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/TilesSfml.cpp \
	$(GRAPHIC_DIR)/Window.cpp \
	$(GRAPHIC_DIR)/Background.cpp\
	$(GRAPHIC_DIR)/TilesSdl.cpp\
	$(LOGIC_DIR)/GameLoop.cpp\

OBJ_FILES := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET := main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean