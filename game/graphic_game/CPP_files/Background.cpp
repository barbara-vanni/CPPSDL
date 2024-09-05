#include "../HPP_files/Background.hpp"

Background::Background() {
    color = {187, 173, 160, 255};  // Background color of 2048
}

void Background::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}
