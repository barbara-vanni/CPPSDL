#include "../HPP_files/Board.hpp"
#include "../HPP_files/Tiles.hpp"
#include "../HPP_files/Input.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ctime> 

/*
This class is the board of the game, it will contain the grid of the game
This class will also contain the logic of the game
This class will contain the logic of the game
*/ 

// Constructor
Board::Board(int size) : size(size) {
    std::cout << "Board constructor called" << std::endl;
    srand(static_cast<unsigned int>(time(0)));
}

// Initialize the board
void Board::boardInit() {   

    if(grid.size() != 0){
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] != nullptr)
                {
                    delete grid[i][j];
                    grid[i][j] = nullptr;
                }
            }
        }
    }
    grid.resize(4, std::vector<Tiles *>(4, nullptr));

    addRandomTile();
    addRandomTile();
}

// Get the grid
std::vector<std::vector<Tiles *>>& Board::getGrid(){
    return grid;
}

// Add a random tile to the board
void Board::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == nullptr) {
                emptyTiles.push_back(std::make_pair(i, j));
            }
        }
    }

    if (emptyTiles.empty())
        return;

    int randIndex = rand() % emptyTiles.size();
    int x = emptyTiles[randIndex].first;
    int y = emptyTiles[randIndex].second;

    int tileValue = (rand() % 10 < 9) ? 2 : 4;
    Tiles *newTile = new Tiles(x, y, tileValue);
    grid[x][y] = newTile;
}

// Move the tiles up
bool Board::moveUp(int& newPoint) {
    
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
                    int valuePoint = grid[k - 1][j]->getNumberInTile() * 2;
                    grid[k - 1][j]->setNumberInTile(valuePoint);
                    newPoint += valuePoint;
                    grid[k][j] = nullptr;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move the tiles to the right
bool Board::moveRight(int& newPoint){
    
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
                    int valuePoint = grid[i][k + 1]->getNumberInTile() * 2;
                    grid[i][k + 1]->setNumberInTile(valuePoint);
                    newPoint += valuePoint;
                    grid[i][k] = nullptr;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move the tiles to the left
bool Board::moveLeft(int& newPoint)
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
                    int valuePoint = grid[i][k - 1]->getNumberInTile() * 2;
                    grid[i][k - 1]->setNumberInTile(valuePoint);
                    newPoint += valuePoint;
                    grid[i][k] = nullptr;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Move the tiles down
bool Board::moveDown(int& newPoint){

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
                    int valuePoint = grid[k + 1][j]->getNumberInTile() * 2;
                    grid[k + 1][j]->setNumberInTile(valuePoint);
                    newPoint += valuePoint;
                    grid[k][j] = nullptr;
                    moved = true;
                }
            }
        }
    }
    return moved;
}

// Check if the player can move
bool Board::okToMove() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == nullptr) {
                return true;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == nullptr) {
                continue;
            }

            if (i > 0 && grid[i][j]->getNumberInTile() == grid[i - 1][j]->getNumberInTile()) {
                return true;
            }

            if (i < 3 && grid[i][j]->getNumberInTile() == grid[i + 1][j]->getNumberInTile()) {
                return true;
            }
            if (j > 0 && grid[i][j]->getNumberInTile() == grid[i][j - 1]->getNumberInTile()) {
                return true;
            }

            if (j < 3 && grid[i][j]->getNumberInTile() == grid[i][j + 1]->getNumberInTile()) {
                return true;
            }
        }
    }
    return false;
}

// Display the board
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
                std::cout << " " << grid[i][j]->getNumberInTile() << "  |";
            }
        }
        std::cout << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

// Destructor
Board::~Board()
{
    std::cout << "Board destructor called" << std::endl;

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