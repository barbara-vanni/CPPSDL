#include "../HPP_files/Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>




Board::Board()
{
    
}

void Board::boardInit()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            grid[i][j] = 0;
        }
    }
    addRandomTile();
    addRandomTile();
}



void Board::addRandomTile()
{   
    std::vector<std::pair<int,int>> emptyTiles;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
            {
                emptyTiles.push_back(std::make_pair(i,j));
            }
        }
    }

    // if there are no empty tiles, return false
    if (emptyTiles.empty()) return;

    // generate a random index to place the tile
    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;

    // generate a 2 with 90% of chance, else generate a 4
    int tileValue = (rand() % 10 < 9) ? 2 : 4;

    grid[x][y] = tileValue;    
}

void Board::displayBoard()
{
    std::cout << "---------------------" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|";
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
            {
                std::cout << "    |";
            }
            else
            {
                std::cout << " " << grid[i][j] << "  |";
            }
        }
        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}


Board::~Board()
{
    
}