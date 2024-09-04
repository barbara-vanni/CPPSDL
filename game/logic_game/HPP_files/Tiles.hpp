#ifndef TILES_HPP
#define TILES_HPP

#include <SDL2/SDL.h>
#include <string>
#include "../../graphic_game/HPP_files/GameObject.hpp"
#include "BoardSdl.hpp"


class Tiles : public GameObject {
public:
    Tiles(int x, int y, int value);   // Constructor
    int getPosX() const;             // Getter for X position
    int getPosY() const;             // Getter for Y position
    int getNumberInTile() const;     // Getter for tile number
    void setPosX(int x);             // Setter for X position
    void setPosY(int y);             // Setter for Y position
    void setNumberInTile(int newValue); // Setter for tile number
    int mergeTilesNumbers(Tiles* tile);
    void render(SDL_Renderer* renderer, int cellSize, BoardSdl* board) const override;
    void update() override; // Update the tile
    ~Tiles();                        // Destructor

private:
    int posX;
    int posY;
    int numberInTile;
};

#endif // TILES_HPP
