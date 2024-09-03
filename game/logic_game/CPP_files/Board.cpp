#include "../HPP_files/Board.hpp"
#include "../HPP_files/Tiles.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>




Board::Board(int size) : size(size)
{  
    std::cout << "Board constructor called" << std::endl;
}

void Board::boardInit()
{
    grid.resize(4, std::vector<Tiles*>(4, nullptr));

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
            if (grid[i][j] == nullptr || grid[i][j]->getNumberInTile() == 0)
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

    // grid[x][y] = tileValue; 
    Tiles* newTile = new Tiles(x, y, tileValue);
    grid[x][y] = newTile;

}

// bool Board::okToMove(){
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (grid[i][j] == nullptr || grid[i][j]->getNumberInTile() == 0)
//             {
//                 return true;
//             }
//             if (i != 3 && grid[i][j]->getNumberInTile() == grid[i + 1][j]->getNumberInTile())
//             {
//                 return true;
//             }
//             if (j != 3 && grid[i][j]->getNumberInTile() == grid[i][j + 1]->getNumberInTile())
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

void Board::displayBoard()
{
    std::cout << "---------------------" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|";
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j]== 0)
            {
                std::cout << "    |";
            }
            else
            {
                std::cout << " " << grid[i][j]->getNumberInTile()  << "  |";
            }
        }
        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}


Board::~Board()
{
  std::cout << "Board destructor called" << std::endl;

    //delete the tiles 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j]; 
                grid[i][j] = nullptr;
            }
        }
    }

}