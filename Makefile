CXX := g++
# Windows path
# CXXFLAGS := -I src/include -I /usr/include/SDL2 -I game
# LDFLAGS := -L src/lib
# LIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lsfml-graphics -lsfml-window -lsfml-system 

# MacOS path
CXXFLAGS := -std=c++14 -I/opt/homebrew/include/SDL2 -Igame -I src/include
LDFLAGS := -L/opt/homebrew/lib
LIBS := -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lncurses -lsfml-graphics -lsfml-window -lsfml-system 

SRC_DIR := game
SRC_FILE := src
GRAPHIC_SDL := $(SRC_DIR)/graphic_game/SDL/CPP_files
GRAPHIC_SFML := $(SRC_DIR)/graphic_game/SFML/CPP_files
GRAPHIC_SFML := $(SRC_DIR)/graphic_game/SFML/CPP_files
LOGIC_DIR := $(SRC_DIR)/logic_game/CPP_files
OBJ_DIR := $(SRC_FILE)/obj

SRC_FILES := main.cpp \
    $(LOGIC_DIR)/Board.cpp \
    $(LOGIC_DIR)/Tiles.cpp \
    $(LOGIC_DIR)/Game.cpp \
    $(LOGIC_DIR)/Input.cpp \
    $(GRAPHIC_SDL)/WindowSdl.cpp \
    $(GRAPHIC_SDL)/GridSdl.cpp \
    $(SRC_DIR)/gameloop.cpp \
    $(GRAPHIC_SFML)//WindowSfml.cpp \
    $(GRAPHIC_SFML)//WindowMenu.cpp \
    $(GRAPHIC_SFML)//GridSfml.cpp \
    $(GRAPHIC_SFML)//TilesSfml.cpp \
    $(GRAPHIC_SFML)//ButtonsSfml.cpp \
    $(GRAPHIC_SFML)//ScoreSfml.cpp \
    $(GRAPHIC_SFML)//WindowRules.cpp \
    $(GRAPHIC_SDL)/Background.cpp\
    $(GRAPHIC_SDL)/TilesSdl.cpp\
    $(GRAPHIC_SDL)/ButtonSdl.cpp\
    $(GRAPHIC_SDL)/ScoreSdl.cpp\
	
	

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
	rm -f *.xml *.html
	rm -f game/test/defeat.txt

test: clean all
	robot game/test/move.robot

.PHONY: all clean