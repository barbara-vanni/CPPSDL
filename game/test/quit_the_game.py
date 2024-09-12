import pyautogui
import time

# Quit the game
pyautogui.moveTo(1255, 170, duration=0.10)
time.sleep(1)
pyautogui.click(button='left', clicks=3, interval=0.30)
time.sleep(3)