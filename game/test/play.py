import pyautogui
import time
import os
import pygetwindow as gw


game_window = gw.getWindowsWithTitle("2048 WindowMenu")[0]


if game_window is not None:

    window_x, window_y, window_width, window_height = (
        game_window.left,
        game_window.top,
        game_window.width,
        game_window.height,
    )

    pyautogui.moveTo(window_x + 310, window_y + 520, duration=0.25)
    pyautogui.click(button="left", clicks=50, interval=0.20)

    pyautogui.press("up")
    time.sleep(0.5)
    pyautogui.press("down")
    time.sleep(0.5)
    pyautogui.press("left")
    time.sleep(0.5)
    pyautogui.press("right")
    time.sleep(0.5)

    pyautogui.moveTo(window_x + 530, window_y + 80, duration=0.10)
    time.sleep(2)
    pyautogui.click(button="left", clicks=1, interval=0.20)
    time.sleep(2)

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

    # Retour au menu principal
    time.sleep(3)
    pyautogui.moveTo(window_x + 530, window_y + 140, duration=0.10)
    time.sleep(1)
    pyautogui.click(button="left", clicks=1, interval=0.30)

    time.sleep(3)
    if os.path.exists("game/test/defeat.txt"):
        os.remove("game/test/defeat.txt")

    # pyautogui.moveTo(window_x + 530, window_y + 80, duration=0.10)
