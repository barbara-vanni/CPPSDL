*** Settings ***
Library  Process
Library  OperatingSystem

*** Test Cases ***
Compile Project Using Make
    Run Process  make  
    Sleep  3s

# Run Project
#     Start Process  ./main
#     Sleep  1s
#     Start Process  python  game/test/move_night_mode.py
#     Sleep  1s
#     # Run Process  python  game/test/quit_the_game.py

RunPlay Project
    Start Process  ./main
    Sleep  1s
    Start Process  python  game/test/move_night_mode.py
    Sleep  1s
    # Run Process  python  game/test/quit_the_game.py
