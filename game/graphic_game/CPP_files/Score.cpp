#include "../HPP_files/Score.hpp"

Score::Score(int x, int y, int init_score) : score(init_score) {
    position.x = x;
    position.y = y;
    position.w = 100;
    position.h = 50;
}

void Score::render(SDL_Renderer* renderer) {
    // Rendering placeholder for the score (for now you can extend with SDL_ttf to render text)
}
