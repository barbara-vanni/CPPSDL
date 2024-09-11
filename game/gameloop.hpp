#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include "SDL2/SDL.h"
#include <iostream>
#include "logic_game/HPP_files/Game.hpp"
#include "logic_game/HPP_files/Input.hpp"
#include "graphic_game/SFML/HPP_files/WindowSfml.hpp"
#include "graphic_game/SFML/HPP_files/WindowMenu.hpp"
#include "graphic_game/SFML/HPP_files/WindowRules.hpp"
#include "graphic_game/SFML/HPP_files/GridSfml.hpp"
#include "graphic_game/SFML/HPP_files/TilesSfml.hpp"
#include "graphic_game/SFML/HPP_files/ButtonsSfml.hpp"
#include "graphic_game/SFML/HPP_files/ScoreSfml.hpp"
#include "graphic_game/HPP_files/WindowSdl.hpp"
#include "graphic_game/HPP_files/GridSdl.hpp"
#include "graphic_game/HPP_files/TilesSdl.hpp"
#include "graphic_game/HPP_files/ButtonSdl.hpp"
#include "graphic_game/HPP_files/ScoreSdl.hpp"

void gameloop();
void runSfml();
void runSdl();
void runHowToPlay();

#endif 
