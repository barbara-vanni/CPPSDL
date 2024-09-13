#include "../HPP_files/Game.hpp"
#include "../HPP_files/Board.hpp"
#include "../HPP_files/Input.hpp"
#include "../src/include/SFML/Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <fstream>

/*
This class is the game class, it will contain the logic of the game
This class will also contain the logic of the game
This class will contain the logic of the game
*/ 

// Constructor
Game::Game() {
    board = new Board(4);
    score.loadScore();
    gameOver = false;
}

// Start the game
void Game::start() {
    board->boardInit();
    board->displayBoard(); 
}

// Reset the game
void Game::reset() {
    start();
    score.actualScore = 0;
}

// Move the tiles
void Game::move() {
    Input input;
    int inputValue = input.getInput();
    int points = 0;
    bool moved = false;

    if (inputValue == 72) {
        moved = board->moveUp(points);
    } else if (inputValue == 80) {
        moved = board->moveDown(points);
    } else if (inputValue == 75) {
        moved = board->moveLeft(points);
    } else if (inputValue == 77) {
        moved = board->moveRight(points);
    } else if (inputValue == 27) {
        gameOver = true;
    }        

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        board->displayBoard();
    }
}

// Move the tiles with SDL
void Game::moveSdl(int inputValue)
{
    int points = 0;
    bool moved = false;

    if (inputValue == SDLK_UP) {
        moved = board->moveUp(points);
    }
    else if (inputValue == SDLK_DOWN) {
        moved = board->moveDown(points);
    }
    else if (inputValue == SDLK_LEFT) {
        moved = board->moveLeft(points);
    }
    else if (inputValue == SDLK_RIGHT) {
        moved = board->moveRight(points);
    }
    else if (inputValue == SDLK_ESCAPE) {
        gameOver = true;
    }

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        board->displayBoard();
        playMoveSound();
    }
}

// Move the tiles with SFML
void Game::moveSfml(int inputValue) {
    int points = 0;
    bool moved = false;

    if (inputValue == sf::Keyboard::Up) {
        moved = board->moveUp(points);
    } else if (inputValue == sf::Keyboard::Down) {
        moved = board->moveDown(points);
    } else if (inputValue == sf::Keyboard::Left) {
        moved = board->moveLeft(points);
    } else if (inputValue == sf::Keyboard::Right) {
        moved = board->moveRight(points);
    } else if (inputValue == sf::Keyboard::Escape) {
        gameOver = true;
    }        

    if (moved) {
        updateScore(points);
        board->addRandomTile();
        board->displayBoard();
        playMoveSound();
    }
}

// Check if the player is defeated
bool Game::checkDefeat() {
    if (board->okToMove() == false) {
        gameOver = true;
        std::ofstream file("game/test/defeat.txt");
        if (file.is_open()){
            file << "true" << std::endl;
            file.close();
        }
        return true;
    }
    else {
        return false;
    }
}

// Display the score
void Game::displayScore() {
    std::cout << "Your score is: " << score.actualScore << std::endl;
    std::cout << "Your best score is: " << score.scoreMax << std::endl;
}

// Update the score
void Game::updateScore(int points) {

    score.actualScore += points;

    if (score.actualScore > score.scoreMax)
    {
        score.scoreMax = score.actualScore;
        score.saveScore();
    }
  
}

// Destructor
Game::~Game() {
    delete board;
}

// Play the move sound
void Game::playMoveSound() {
    static bool audio_initialized = false;
    if (!audio_initialized) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
            return;
        }
        audio_initialized = true;
    }

    static Mix_Chunk* moveSound = nullptr;
    if (!moveSound) {
        moveSound = Mix_LoadWAV("assets/sounds/move.wav");
        if (moveSound == nullptr) {
            std::cerr << "Failed to load move sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
            return;
        }
    }

    int volume = Mix_Volume(-1, -1); 
    if (volume == 0) {
        Mix_Volume(-1, MIX_MAX_VOLUME); 
    }

    if (Mix_PlayChannel(-1, moveSound, 0) == -1) {
        std::cerr << "Failed to play sound! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}