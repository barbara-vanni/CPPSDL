import pyautogui
import time
import os
import pygetwindow as gw


game_window = gw.getWindowsWithTitle('2048 WindowMenu')[0]  

print("j'ouvre la fenetre du jeu")
if game_window is not None:
    window_x, window_y, window_width, window_height = game_window.left, game_window.top, game_window.width, game_window.height
    # pyautogui.moveTo(window_x + 310, window_y + 520, duration=0.25)
    pyautogui.moveTo(window_x + 310, window_y + 400, duration=0.25)
    pyautogui.click(button='left', clicks=50, interval=0.30)


# Move the character in the game
while True:
    if os.path.exists("game/test/defeat.txt"):
        with open("game/test/defeat.txt", "r") as file:
            status = file.read().strip()
            if status == "true":
                print("Game Over detected. Exiting loop.")
                break  

    pyautogui.press("up")
    print("up")
    if os.path.exists("defeat.txt"):
        with open("defeat.txt", "r") as file:
            status = file.read().strip()
            if status == "true":
                break

    pyautogui.press("down")
    print("down")
    if os.path.exists("defeat.txt"):
        with open("defeat.txt", "r") as file:
            status = file.read().strip()
            if status == "true":
                break

    pyautogui.press("left")
    print("left")
    if os.path.exists("defeat.txt"):
        with open("defeat.txt", "r") as file:
            status = file.read().strip()
            if status == "true":
                break

    pyautogui.press("right")
    print("right")
    if os.path.exists("defeat.txt"):
        with open("defeat.txt", "r") as file:
            status = file.read().strip()
            if status == "true":
                break

# Back to the main menu
time.sleep(3)
pyautogui.moveTo(window_x + 570, window_y + 180, duration=0.25)
pyautogui.click(button='left', clicks=3, interval=0.30)
time.sleep(1)
pyautogui.moveTo(window_x + 590, window_y + 5, duration=0.25)

time.sleep(1)
if os.path.exists("game/test/defeat.txt"):
    os.remove("game/test/defeat.txt")
