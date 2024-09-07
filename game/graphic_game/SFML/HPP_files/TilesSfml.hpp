#ifndef TILESsfml_HPP
#define TILESsfml_HPP

#include "../../GameObject.hpp"
#include "../../../logic_game/HPP_files/Tiles.hpp"
#include "../../../logic_game/HPP_files/Game.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"


class TilesSfml : public GameObject {
    private:
        Game& game;
        Tiles* currentTile;
        int tileWidth;
        int tileHeight;
        int gridSize;
        int gridPosX;
        int gridPosY;
        sf::Color getTileColor(int value);

    public:
        TilesSfml(Game& game);
        ~TilesSfml();

        double posX() override;
        double posY() override;
        double width() override;
        double height() override;
        void drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY, int gridSize);
        void setTile(Tiles* tile, int gridSize);
};

#endif