*** Settings ***
Library  Process
Library  OperatingSystem

*** Test Cases ***
Clean Project
    Run Process  make  clean


Compile Project Using Make
    Run Process  make  
    Sleep  3s

Run Project
    Start Process  ./main
    Sleep  1s
    Start Process  python  game/test/move.py










