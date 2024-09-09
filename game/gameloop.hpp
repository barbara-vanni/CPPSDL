#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include "SDL2/SDL.h"
#include <iostream>
#include "logic_game/HPP_files/Game.hpp"
#include "logic_game/HPP_files/Input.hpp"
#include "graphic_game/SFML/HPP_files/WindowSfml.hpp"
#include "graphic_game/SFML/HPP_files/WindowMenu.hpp"
#include "graphic_game/SFML/HPP_files/GridSfml.hpp"
#include "graphic_game/SFML/HPP_files/TilesSfml.hpp"
#include "graphic_game/SFML/HPP_files/ButtonSfml.hpp"
#include "graphic_game/HPP_files/Window.hpp"
#include "graphic_game/HPP_files/GridSdl.hpp"
#include "graphic_game/HPP_files/TilesSdl.hpp"
#include "logic_game/HPP_files/BoardSdl.hpp"
#include "graphic_game/HPP_files/ButtonSdl.hpp"

void gameloop();
void runSfml();
void runSdl();
// void runHowToPlay();

#endif 
