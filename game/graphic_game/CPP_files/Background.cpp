#include "../HPP_files/Background.hpp"

Background::Background() {
    color = {0, 0, 0, 255};  // Black background
}

void Background::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}
