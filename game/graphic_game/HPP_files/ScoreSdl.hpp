#pragma once 
#include <SDL2/SDL.h>   
#include <SDL2/SDL_ttf.h>  
#include <string>
#include "../GameObject.hpp"
#include "../../logic_game/HPP_files/Game.hpp"
 


class ScoreSdl : public GameObject {
public:
    // Constructor: Initialize the ScoreSdl with game reference and position
    ScoreSdl(Game& game, double x, double y);
    
    // Destructor: Clean up resources
    ~ScoreSdl();

    // Override position and size methods from GameObject
    double posX() override;
    double posY() override;
    double width() override;
    double height() override;

    // Update the score string based on the current game score
    void updateActualScore(int score);
    void updateBestScore(int score);
    // void resetScore();

    // Draw the score on the SDL renderer
    void draw(SDL_Renderer* renderer);
    void drawDefeat(SDL_Renderer* renderer);

private:
    Game& game;  // Reference to the Game object to get score info
    
    TTF_Font* font;  // Font for rendering text
    std::string currentLabel;  // Current text to display ("Score: X | Best: Y")
    double scorePosX;  // X position of the score display
    double scorePosY;  // Y position of the score display
};
