#pragma once
#include <iostream>


class Board {
    public:
        Board();
        ~Board();
        void printBoard();
        void setTile(int x, int y, char tile);
        char getTile(int x, int y);
        void setBoardSize(int size);
        int getBoardSize;


    private:

        char** board;
        int boardSize;
};



