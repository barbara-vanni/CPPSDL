#include <iostream>
#include <SDL2/SDL.h>
#include "../HPP_files/Tiles.hpp"
#include "../HPP_files/Grid.hpp"



Tiles::Tiles()
{
    rect.x = 0;
    rect.y= 0;
    rect.w = 150;
    rect.h = 150;
    color = {0,0,0,255};
    value = 0;
}

Tiles::~Tiles()
{
}


double Tiles::posX(double x){
    rect.x = x;
    return rect.x;
}

double Tiles::posY(double y){
    rect.y = y;
    return rect.y;
}

int Tiles::size(int size){
    rect.w = size;
    rect.h = size;
    return rect.w;
}

int Tiles::getValue(){
    return value;
}

void Tiles::setValue(int value){
    this->value = value;
}

// void Tiles::mergeTiles(SDL_Renderer* renderer,){
//     grid[i][j] = grid[i][j] * 2;
//     grid[i2][j2] = 0;
// }


void Tiles::displayTiles(SDL_Renderer* renderer, int** grid, const Grid& gridObject) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != 0) {
                // Set tile color based on the value
                if (grid[i][j] == 2) {
                    color = {255, 255, 255, 255};  // White for 2
                } else if (grid[i][j] == 4) {
                    color = {255, 255, 0, 255};    // Yellow for 4
                } else if (grid[i][j] == 8) {
                    color = {255, 0, 255, 255};    // Magenta for 8
                } else if (grid[i][j] == 16) {
                    color = {0, 255, 255, 255};    // Cyan for 16
                } else if (grid[i][j] == 32) {
                    color = {255, 0, 0, 255};      // Red for 32
                } else if (grid[i][j] == 64) {
                    color = {0, 255, 0, 255};      // Green for 64
                } else if (grid[i][j] == 128) {
                    color = {0, 0, 255, 255};      // Blue for 128
                } else if (grid[i][j] == 256) {
                    color = {255, 255, 255, 255};  // White for 256
                } else if (grid[i][j] == 512) {
                    color = {255, 255, 0, 255};    // Yellow for 512
                } else if (grid[i][j] == 1024) {
                    color = {255, 0, 255, 255};    // Magenta for 1024
                } else if (grid[i][j] == 2048) {
                    color = {0, 255, 255, 255};    // Cyan for 2048
                } else if (grid[i][j] > 2048) {
                    color = {255, 0, 0, 255};      // Red for > 2048
                }

                // Set the tile's position based on the grid position
                rect.x = gridObject.rect.x + j * gridObject.rect.w;
                rect.y = gridObject.rect.y + i * gridObject.rect.h;

                // Set tile size (same as grid cell size)
                rect.w = gridObject.rect.w;
                rect.h = gridObject.rect.h;

                // Draw the tile
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}



void Tiles::moveTiles(SDL_Renderer* renderer, int** grid, int direction){
    if (direction == 1){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if (grid[i][j] != 0){
                    int k = j;
                    while (k > 0 && grid[i][k - 1] == 0){
                        k--;
                    }
                    if (k != j){
                        grid[i][k] = grid[i][j];
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 2){
        for (int i = 0; i < 4; i++){
            for (int j = 3; j >= 0; j--){
                if (grid[i][j] != 0){
                    int k = j;
                    while (k < 3 && grid[i][k + 1] == 0){
                        k++;
                    }
                    if (k != j){
                        grid[i][k] = grid[i][j];
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 3){
        for (int j = 0; j < 4; j++){
            for (int i = 0; i < 4; i++){
                if (grid[i][j] != 0){
                    int k = i;
                    while (k > 0 && grid[k - 1][j] == 0){
                        k--;
                    }
                    if (k != i){
                        grid[k][j] = grid[i][j];
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (direction == 4){
        for (int j = 0; j < 4; j++){
            for (int i = 3; i >= 0; i--){
                if (grid[i][j] != 0){
                    int k = i;
                    while (k < 3 && grid[k + 1][j] == 0){
                        k++;
                    }
                    if (k != i){
                        grid[k][j] = grid[i][j];
                        grid[i][j] = 0;
                    }
                }
            }
        }
    }
}

