import pyautogui
import time
import os
import pygetwindow as gw

# Function to move the tiles in the game
# This function is used to play the game
# The function moves the tiles in the game window
# The function also checks if the game is over
# The function removes the defeat.txt file

def move_night_mode():
    # Get the game window
    game_window = gw.getWindowsWithTitle('2048 WindowMenu')[0]  

    # If the game window is found, move the mouse to the game window and click 50 times
    if game_window is not None:
        window_x, window_y, window_width, window_height = game_window.left, game_window.top, game_window.width, game_window.height
        pyautogui.moveTo(window_x + 310, window_y + 520, duration=0.25)
        pyautogui.click(button='left', clicks=50, interval=0.30)

    while True:
        # Check if the game is over
        if os.path.exists("game/test/defeat.txt"):
            with open("game/test/defeat.txt", "r") as file:
                status = file.read().strip()
                if status == "true":
                    break  

        # Arrow keys to move the tiles
        pyautogui.press("up")
        time.sleep(0.1)
        if os.path.exists("defeat.txt"):
            with open("defeat.txt", "r") as file:
                status = file.read().strip()
                if status == "true":
                    break

        pyautogui.press("down")
        time.sleep(0.1)
        if os.path.exists("defeat.txt"):
            with open("defeat.txt", "r") as file:
                status = file.read().strip()
                if status == "true":
                    break

        pyautogui.press("left")
        time.sleep(0.1)
        if os.path.exists("defeat.txt"):
            with open("defeat.txt", "r") as file:
                status = file.read().strip()
                if status == "true":
                    break

        pyautogui.press("right")
        time.sleep(0.1)
        if os.path.exists("defeat.txt"):
            with open("defeat.txt", "r") as file:
                status = file.read().strip()
                if status == "true":
                    break

    # Move the mouse to menu button and click
    time.sleep(3)
    pyautogui.moveTo(window_x + 570, window_y + 180, duration=0.25)
    pyautogui.click(button='left', clicks=3, interval=0.30)

    # Remove the defeat.txt file
    time.sleep(1)
    if os.path.exists("game/test/defeat.txt"):
        os.remove("game/test/defeat.txt")
