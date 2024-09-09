#include "../HPP_files/Background.hpp"
#include <iostream>
#include <SDL2/SDL.h>


Background::Background(double x, double y, double w, double h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    color = {187, 173, 160, 255};
}

double Background::posX() {
    return x;
}

double Background::posY() {
    return y;
}

double Background::width() {
    return w;
}

double Background::height() {
    return h;
}

void Background::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}


Background::~Background() {
    std::cout << "Background destroyed" << std::endl;
}


