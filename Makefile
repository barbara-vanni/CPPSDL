CXX := g++
# Windows path
# CXXFLAGS := -I src/include -I /usr/include/SDL2 -I game
# LDFLAGS := -L src/lib
# LIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lsfml-graphics -lsfml-window -lsfml-system

# MacOS path
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
	$(GRAPHIC_DIR)/WindowSdl.cpp \
	$(GRAPHIC_DIR)/GridSdl.cpp \
	$(SRC_DIR)/gameloop.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/WindowSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/WindowMenu.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/GridSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/TilesSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/ButtonsSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/ScoreSfml.cpp \
	$(SRC_DIR)/graphic_game/SFML/CPP_files/WindowRules.cpp \
	$(GRAPHIC_DIR)/Background.cpp\
	$(GRAPHIC_DIR)/TilesSdl.cpp\
	$(GRAPHIC_DIR)/ButtonSdl.cpp\
	$(GRAPHIC_DIR)/ScoreSdl.cpp\
	

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