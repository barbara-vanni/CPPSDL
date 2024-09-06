#include "../GameObject.hpp"
#include "../../logic_game/HPP_files/Tiles.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class TilesSdl : public GameObject {
public:
    Tiles *tiles;
    TilesSdl(double x, double y, double w, double h, int numberInTile);
    double posX() override;
    double posY() override;
    double width() override;
    double height() override;
    void draw(SDL_Renderer* renderer);
    ~TilesSdl() override;

private:
    SDL_Color color;
    TTF_Font* font; // For font management
    double x;
    double y;
    double w;
    double h;
};
