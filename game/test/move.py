import pyautogui
import time

# Move the mouse to the game window
pyautogui.moveTo(960, 660, duration=0.25)
# time.sleep(5)
pyautogui.click(button='left', clicks=30, interval=0.20)


# Move the character in the game
pyautogui.press("up")
time.sleep(1)
print("up")
pyautogui.press("down")
time.sleep(1)
print("down")
pyautogui.press("left")
time.sleep(1)
print("left")
pyautogui.press("right")
time.sleep(1)
print("right")

pyautogui.moveTo(1255, 170, duration=0.10)
time.sleep(1)
pyautogui.click(button='left', clicks=3, interval=0.30)
