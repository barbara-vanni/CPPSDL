#include "../HPP_files/Button.hpp"

Button::Button(int x, int y, int w, int h, std::string lbl) : label(lbl) {
    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;
    color = {100, 100, 100, 255};  // Gray button color
}

void Button::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &position);
}
