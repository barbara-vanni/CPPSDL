*** Settings ***
Library  Process
Library  OperatingSystem

*** Test Cases ***
Compile Project Using Make
    Run Process  make  
    Sleep  3s

RunPlay Project
    Start Process  ./main
    Sleep  1s
    Start Process  python  game/test/run_test.py
    Sleep  1s
