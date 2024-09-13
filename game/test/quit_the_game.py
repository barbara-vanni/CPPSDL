import pyautogui
import time
import pygetwindow as gw

# This function is used to quit the game
# The function quits the game by clicking the cross button

def quit_the_game():
    # Get the game window
    game_window = gw.getWindowsWithTitle("2048 WindowMenu")[0]

    if game_window is not None:
        window_x, window_y, window_width, window_height = game_window.left, game_window.top, game_window.width, game_window.height
        time.sleep(1)
        # Move the mouse to the cross button and click
        pyautogui.moveTo(window_x + 590, window_y + 5, duration=0.25)
        pyautogui.click(button='left', clicks=1, interval=0.30)
