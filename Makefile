CXX := g++
CXXFLAGS := -I src/include -I /usr/include/SDL2 -I game
LDFLAGS := -L src/lib
LIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer 

# Directories
SRC_DIR := game
SRC_FILE:= src
GRAPHIC_DIR := $(SRC_DIR)/graphic_game/CPP_files
LOGIC_DIR := $(SRC_DIR)/logic_game/CPP_files
OBJ_DIR := $(SRC_FILE)/obj

# Source files
SRC_FILES := main.cpp \
	$(LOGIC_DIR)/Board.cpp \
	$(LOGIC_DIR)/Tiles.cpp \
	$(LOGIC_DIR)/Game.cpp \
	$(LOGIC_DIR)/Input.cpp \
	$(GRAPHIC_DIR)/Window.cpp \

# Object files
OBJ_FILES := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable
TARGET := main

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

# Compile source files into object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
