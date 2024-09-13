import pyautogui
import time
import pygetwindow as gw

# This function is used to move the mouse to the how to play button in the game window
# The function then clicks to move to the next page
# The function then moves the mouse to the back button to go back to the main menu

def move_how_to_play():
    game_window = gw.getWindowsWithTitle("2048 WindowMenu")[0]

    # If the game window is found, move the mouse to the game window and click 50 times
    if game_window is not None:
        # Get the rules window
        window_x, window_y, window_width, window_height = game_window.left, game_window.top, game_window.width, game_window.height
        pyautogui.moveTo(window_x + 310, window_y + 660, duration=0.25)
        pyautogui.click(button='left', clicks=50, interval=0.30)
        time.sleep(10)

        # back to the main menu
        pyautogui.moveTo(window_x + 570, window_y + 150, duration=0.25)
        pyautogui.click(button='left', clicks=3, interval=0.30)
