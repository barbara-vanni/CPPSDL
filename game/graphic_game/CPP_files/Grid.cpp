#include "../HPP_files/Grid.hpp"
#include <iostream>
#include <SDL2/SDL.h>



Grid::Grid(){
    rect.x = 0;
    rect.y = 0;
    rect.w = 150; // CELL SIZE
    rect.h = 150; // CELL SIZE
    color = {255,255,255,255};
}

Grid::~Grid(){
}

double Grid::posX(double x){
    rect.x = x;
    return rect.x;
}

double Grid::posY(double y){
    rect.y = y;
    return rect.y;
}

int Grid::size(int size){
    rect.w = size;
    rect.h = size;
    return rect.w;
}

void Grid::displayGrid(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int i = 0; i < 5; i++){
        SDL_RenderDrawLine(renderer, rect.x + i * rect.w, rect.y, rect.x + i * rect.w, rect.y + rect.h * 4);
        SDL_RenderDrawLine(renderer, rect.x, rect.y + i * rect.h, rect.x + rect.w * 4, rect.y + i * rect.h);
    }
}

void Grid::checkDefeat(SDL_Renderer* renderer, int** grid){
    int count = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (grid[i][j] == 0){
                count++;
            }
        }
    }
    if (count == 0){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x + rect.w * 4, rect.y + rect.h * 4);
        SDL_RenderDrawLine(renderer, rect.x + rect.w * 4, rect.y, rect.x, rect.y + rect.h * 4);
    }
}

void Grid::addNewTile(SDL_Renderer* renderer, int** grid){
    int x = rand() % 4;
    int y = rand() % 4;
    while (grid[x][y] != 0){
        x = rand() % 4;
        y = rand() % 4;
    }
    grid[x][y] = 2;
}

void Grid::okToMove(SDL_Renderer* renderer, int** grid){
    int count = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (grid[i][j] == 0){
                count++;
            }
        }
    }

}
