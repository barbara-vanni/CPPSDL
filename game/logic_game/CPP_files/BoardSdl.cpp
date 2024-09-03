//BoardSdl.cpp


#include "../HPP_files/BoardSdl.hpp"
#include <cstdlib>
#include <ctime>

// Constructor
BoardSdl::BoardSdl(int size) : size(size), font(nullptr) {
    if (!initSDL_TTF()) {
        std::cerr << "Failed to initialize SDL_ttf" << std::endl;
    }
    boardInit();
}

// Destructor
BoardSdl::~BoardSdl() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            delete grid[i][j];
        }
    }
    closeSDL_TTF();  // Clean up SDL_ttf
}

// Initialize board
void BoardSdl::boardInit() {
    grid.resize(size);
    for (int i = 0; i < size; i++) {
        grid[i].resize(size);
        for (int j = 0; j < size; j++) {
            grid[i][j] = new Tiles(i, j, 0);
        }
    }
    addRandomTile();
    addRandomTile();
}

// Add a random tile
void BoardSdl::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getNumberInTile() == 0) {
                emptyTiles.push_back(std::make_pair(i, j));
            }
        }
    }
    if (emptyTiles.empty()) {
        return;
    }
    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;
    int tileValue = (rand() % 10 < 9) ? 2 : 4;
    grid[x][y]->setNumberInTile(tileValue);
}

// Get tile color
SDL_Color BoardSdl::getTileColor(int value) {
    switch (value) {
        case 2: return {238, 228, 218, 255};
        case 4: return {237, 224, 200, 255};
        case 8: return {242, 177, 121, 255};
        case 16: return {245, 149, 99, 255};
        case 32: return {246, 124, 95, 255};
        case 64: return {246, 94, 59, 255};
        case 128: return {237, 207, 114, 255};
        case 256: return {237, 204, 97, 255};
        case 512: return {237, 200, 80, 255};
        case 1024: return {237, 197, 63, 255};
        case 2048: return {237, 194, 46, 255};
        default: return {204, 192, 179, 255}; 
    }
}

// Move up
bool BoardSdl::moveUp() {
    bool moved = false;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (grid[i][j]->getNumberInTile() != 0) {
                int k = i;
                while (k > 0 && (grid[k - 1][j]->getNumberInTile() == 0)) {
                    grid[k - 1][j]->setNumberInTile(grid[k][j]->getNumberInTile());
                    grid[k][j]->setNumberInTile(0);
                    moved = true;
                    k--;
                }
                if (k > 0 && grid[k - 1][j]->getNumberInTile() == grid[k][j]->getNumberInTile()) {
                    grid[k - 1][j]->setNumberInTile(grid[k - 1][j]->getNumberInTile() * 2);
                    grid[k][j]->setNumberInTile(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move down
bool BoardSdl::moveDown() {
    bool moved = false;
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i >= 0; i--) {
            if (grid[i][j]->getNumberInTile() != 0) {
                int k = i;
                while (k < size - 1 && (grid[k + 1][j]->getNumberInTile() == 0)) {
                    grid[k + 1][j]->setNumberInTile(grid[k][j]->getNumberInTile());
                    grid[k][j]->setNumberInTile(0);
                    moved = true;
                    k++;
                }
                if (k < size - 1 && grid[k + 1][j]->getNumberInTile() == grid[k][j]->getNumberInTile()) {
                    grid[k + 1][j]->setNumberInTile(grid[k + 1][j]->getNumberInTile() * 2);
                    grid[k][j]->setNumberInTile(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move left
bool BoardSdl::moveLeft() {
    bool moved = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getNumberInTile() != 0) {
                int k = j;
                while (k > 0 && (grid[i][k - 1]->getNumberInTile() == 0)) {
                    grid[i][k - 1]->setNumberInTile(grid[i][k]->getNumberInTile());
                    grid[i][k]->setNumberInTile(0);
                    moved = true;
                    k--;
                }
                if (k > 0 && grid[i][k - 1]->getNumberInTile() == grid[i][k]->getNumberInTile()) {
                    grid[i][k - 1]->setNumberInTile(grid[i][k - 1]->getNumberInTile() * 2);
                    grid[i][k]->setNumberInTile(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move right
bool BoardSdl::moveRight() {
    bool moved = false;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (grid[i][j]->getNumberInTile() != 0) {
                int k = j;
                while (k < size - 1 && (grid[i][k + 1]->getNumberInTile() == 0)) {
                    grid[i][k + 1]->setNumberInTile(grid[i][k]->getNumberInTile());
                    grid[i][k]->setNumberInTile(0);
                    moved = true;
                    k++;
                }
                if (k < size - 1 && grid[i][k + 1]->getNumberInTile() == grid[i][k]->getNumberInTile()) {
                    grid[i][k + 1]->setNumberInTile(grid[i][k + 1]->getNumberInTile() * 2);
                    grid[i][k]->setNumberInTile(0);
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Check if a move is possible
bool BoardSdl::okToMove() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j]->getNumberInTile() == 0) {
                return true;
            }
            if (i > 0 && grid[i][j]->getNumberInTile() == grid[i - 1][j]->getNumberInTile()) {
                return true;
            }
            if (i < size - 1 && grid[i][j]->getNumberInTile() == grid[i + 1][j]->getNumberInTile()) {
                return true;
            }
            if (j > 0 && grid[i][j]->getNumberInTile() == grid[i][j - 1]->getNumberInTile()) {
                return true;
            }
            if (j < size - 1 && grid[i][j]->getNumberInTile() == grid[i][j + 1]->getNumberInTile()) {
                return true;
            }
        }
    }
    return false;
}

// Initialize SDL_ttf
bool BoardSdl::initSDL_TTF() {
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
        return false;
    }
    font = TTF_OpenFont("/Users/mathisserra/Desktop/Github/B2_Laplateforme/CPPSDL/assets/minecraft_font.ttf", 50);
    if (font == nullptr) {
        std::cerr << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
        return false;
    }
    textColor = {0, 0, 0, 255};
    return true;
}

// Close SDL_ttf
void BoardSdl::closeSDL_TTF() {
    TTF_CloseFont(font);
    TTF_Quit();
}


// Render board
void BoardSdl::renderBoard(SDL_Renderer* renderer, int cellSize) {
    // Clear the renderer to avoid artifacts
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set background color to white
    SDL_RenderClear(renderer);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Draw tile background
            SDL_Rect tileRect = { j * cellSize, i * cellSize, cellSize, cellSize };
            int tileValue = grid[i][j]->getNumberInTile();
            SDL_Color tileColor = getTileColor(tileValue);

            SDL_SetRenderDrawColor(renderer, tileColor.r, tileColor.g, tileColor.b, tileColor.a);
            SDL_RenderFillRect(renderer, &tileRect);

            // Draw number if the tile is not empty
            if (tileValue != 0) {
                std::string tileText = std::to_string(tileValue);
                SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, tileText.c_str(), textColor);

                if (surfaceMessage == nullptr) {
                    std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
                    continue;
                }

                SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                if (message == nullptr) {
                    std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
                    SDL_FreeSurface(surfaceMessage);
                    continue;
                }

                int textWidth = surfaceMessage->w;
                int textHeight = surfaceMessage->h;
                SDL_Rect messageRect = {
                    j * cellSize + (cellSize - textWidth) / 2,
                    i * cellSize + (cellSize - textHeight) / 2,
                    textWidth,
                    textHeight
                };

                SDL_RenderCopy(renderer, message, nullptr, &messageRect);

                SDL_DestroyTexture(message);
                SDL_FreeSurface(surfaceMessage);
            }
        }
    }

    // Present the updated frame
    SDL_RenderPresent(renderer);
}
