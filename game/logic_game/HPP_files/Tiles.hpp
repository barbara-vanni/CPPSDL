// Tile.hpp
#ifndef TILE_HPP
#define TILE_HPP

#include "../../graphic_game/HPP_files/GameObject.hpp"

class Tile : public GameObject {
public:
    Tile(int posX, int posY, int numberInTile);
    ~Tile();

    int getPosX() const;
    int getPosY() const;
    int getNumberInTile() const;
    void setPosX(int posX);
    void setPosY(int posY);
    void setNumberInTile(int numberInTile);
    

    void draw(SDL_Renderer* renderer) const override;

private:
    int posX;
    int posY;
    int numberInTile;


};

#endif // TILE_HPP
