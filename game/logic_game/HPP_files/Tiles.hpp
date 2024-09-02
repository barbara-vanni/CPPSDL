#ifndef TILES_HPP
#define TILES_HPP

#include <iostream>
class Tiles {
    private:
    int tileHeight = 145;
    int tileWidth = 145;
    int posX;
    int posY;
    int numberInTile;

public:
    Tiles(int posX, int posY, int numberInTile);
    ~Tiles();

    // Getters
    int getPosX();
    int getPosY();
    int getNumberInTile();

    // Setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setNumberInTile(int numberInTile);

    // Other methods
    int mergeTilesNumbers(Tiles* tile);

};

#endif