#ifndef TILESsfml_HPP
#define TILESsfml_HPP

#include "../../GameObject.hpp"
#include "../../../logic_game/HPP_files/Tiles.hpp"
#include "../../../logic_game/HPP_files/Game.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"


class TilesSfml : public GameObject {
    private:
        Game& game;
        int tileWidth;
        int tileHeight;

    public:
        TilesSfml(Game& game);
        ~TilesSfml();

        double posX() override;
        double posY() override;
        double width() override;
        double height() override;
        void drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY);

    private:
        sf::Color getTileColor(int value);
};

#endif