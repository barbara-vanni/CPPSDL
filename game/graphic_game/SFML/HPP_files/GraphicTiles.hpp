#ifndef GRAPHICTILES_HPP
#define GRAPHICTILES_HPP

#include "../../GameObject.hpp"
#include "../../../logic_game/HPP_files/Tiles.hpp"
#include "../../../../src/include/SFML/Graphics.hpp"


class GraphicTiles : public GameObject {
    private:
        int tileWidth = 140;
        int tileHeight = 140;

    public:
        // Tiles* getTile();

        GraphicTiles();
        ~GraphicTiles();

        double posX() override;
        double posY() override;
        double width() override;
        double height() override;

        void drawTile(sf::RenderWindow* window, Tiles* tile, int gridPosX, int gridPosY);
        sf::Color getTileColor(int value);
};

#endif