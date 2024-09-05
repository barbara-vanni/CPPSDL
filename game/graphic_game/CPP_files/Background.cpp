#include "../HPP_files/Background.hpp"

Background::Background() {
    color = {187, 173, 160, 255};  // Background color of 2048
    rect.x = 0;
    rect.y = 0;
    rect.w = 800;
    rect.h = 600;
}

Background::~Background() {
}

double Background::posX(double x) {
    rect.x = x;
    return rect.x;
}

double Background::posY(double y) {
    rect.y = y;
    return rect.y;
}

int Background::size(int size) {
    rect.w = size;
    rect.h = size;
    return rect.w;
}

void Background::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
