import pyautogui
import time
import os


# Move the mouse to the game window
pyautogui.moveTo(960, 660, duration=0.25)
pyautogui.click(button='left', clicks=50, interval=0.20)


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


print("sortie de boucle ok")
time.sleep(3)
pyautogui.moveTo(1255, 170, duration=0.10)
time.sleep(1)
pyautogui.click(button='left', clicks=3, interval=0.30)
