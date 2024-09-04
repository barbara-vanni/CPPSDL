// Board.cpp
#include "../HPP_files/Board.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board(int size) : size(size) {
    grid.resize(size, std::vector<Tile*>(size, nullptr));
    boardInit();
}

Board::~Board() {
    for (auto& row : grid) {
        for (auto& tile : row) {
            delete tile;
        }
    }
}

void Board::boardInit() {
    addRandomTile();
    addRandomTile();
}

void Board::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == nullptr) {
                emptyTiles.emplace_back(i, j);
            }
        }
    }
    
    if (emptyTiles.empty()) return;

    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;

    int tileValue = (rand() % 10 < 9) ? 2 : 4;
    grid[x][y] = new Tile(x, y, tileValue);
}


bool Board::moveUp()
{
    bool moved = false;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (grid[i][j] != nullptr)
            {
                int k = i;
                while (k > 0 && (grid[k - 1][j] == nullptr || grid[k - 1][j]->getNumberInTile() == 0))
                {
                    grid[k - 1][j] = grid[k][j];
                    grid[k][j] = nullptr;
                    grid[k - 1][j]->setPosX(k - 1);
                    moved = true;
                    k--;
                }
                if (k > 0 && grid[k - 1][j]->getNumberInTile() == grid[k][j]->getNumberInTile())
                {
                    grid[k - 1][j]->setNumberInTile(grid[k - 1][j]->getNumberInTile() * 2);
                    grid[k][j] = nullptr;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::moveRight()
{

    bool moved = false;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (grid[i][j] != nullptr)
            {

                int k = j;

                while (k < 3 && (grid[i][k + 1] == nullptr || grid[i][k + 1] == 0))
                {
                    grid[i][k + 1] = grid[i][k];
                    grid[i][k] = nullptr;
                    grid[i][k + 1]->setPosY(k + 1);
                    moved = true;
                    k++;
                }

                if (k < 3 && grid[i][k + 1]->getNumberInTile() == grid[i][k]->getNumberInTile())
                {
                    grid[i][k + 1]->setNumberInTile(grid[i][k + 1]->getNumberInTile() * 2);
                    grid[i][k] = nullptr;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::moveLeft()
{

    bool moved = false;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] != nullptr)
            {

                int k = j;

                while (k > 0 && (grid[i][k - 1] == nullptr || grid[i][k - 1] == 0))
                {
                    grid[i][k - 1] = grid[i][k];
                    grid[i][k] = nullptr;
                    grid[i][k - 1]->setPosY(k - 1);
                    moved = true;
                    k--;
                }

                if (k > 0 && grid[i][k - 1]->getNumberInTile() == grid[i][k]->getNumberInTile())
                {
                    grid[i][k - 1]->setNumberInTile(grid[i][k - 1]->getNumberInTile() * 2);
                    grid[i][k] = nullptr;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

bool Board::moveDown(){

    bool moved = false;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (grid[i][j] != nullptr)
            {
                int k = i;
                while (k < 3 && (grid[k + 1][j] == nullptr || grid[k + 1][j]->getNumberInTile() == 0))
                {
                    grid[k + 1][j] = grid[k][j];
                    grid[k][j] = nullptr;
                    grid[k + 1][j]->setPosX(k + 1);
                    moved = true;
                    k++;
                }
                if (k < 3 && grid[k + 1][j]->getNumberInTile() == grid[k][j]->getNumberInTile())
                {
                    grid[k + 1][j]->setNumberInTile(grid[k + 1][j]->getNumberInTile() * 2);
                    grid[k][j] = nullptr;
                    moved = true;
                }
            }
        }
    }

    return moved;
}

bool Board::okToMove(){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == nullptr)
            {
                return true;
            }
            if (i > 0 && grid[i][j]->getNumberInTile() == grid[i - 1][j]->getNumberInTile())
            {
                return true;
            }
            if (i < 3 && grid[i][j]->getNumberInTile() == grid[i + 1][j]->getNumberInTile())
            {
                return true;
            }
            if (j > 0 && grid[i][j]->getNumberInTile() == grid[i][j - 1]->getNumberInTile())
            {
                return true;
            }
            if (j < 3 && grid[i][j]->getNumberInTile() == grid[i][j + 1]->getNumberInTile())
            {
                return true;
            }
        }
    }
    return false;
}

// void Board::displayBoard()
// {
//     std::cout << "---------------------" << std::endl;
//     for (int i = 0; i < 4; i++)
//     {
//         std::cout << "|";
//         for (int j = 0; j < 4; j++)
//         {
//             if (grid[i][j] == 0)
//             {
//                 std::cout << "    |";
//             }
//             else
//             {
//                 std::cout << " " << grid[i][j]->getNumberInTile() << "  |";
//             }
//         }
//         std::cout << std::endl;
//         std::cout << "---------------------" << std::endl;
//     }
// }


void Board::displayBoard(SDL_Renderer* renderer) const {
    for (auto& row : grid) {
        for (auto& tile : row) {
            if (tile) {
                tile->draw(renderer);
            }
        }
    }
}


Board::~Board()
{
    std::cout << "Board destructor called" << std::endl;

    // delete the tiles
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (grid[i][j] != nullptr)
            {
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
}