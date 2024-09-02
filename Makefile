CXX := g++
CXXFLAGS := -I src/include -I /usr/include/SDL2 -I game
LDFLAGS := -L src/lib
LIBS := -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer 

# Directories
SRC_DIR := game
GRAPHIC_DIR := $(SRC_DIR)/graphic_game/CPP_files
LOGIC_DIR := $(SRC_DIR)/logic_game/CPP_files

# Source files
SRC_FILES := main.cpp \
	$(LOGIC_DIR)/Tiles.cpp \

# Object files
OBJ_FILES := $(SRC_FILES:.cpp=.o)

# Executable
TARGET := main

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Phony targets
.PHONY: all clean
