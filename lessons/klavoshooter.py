import pytesseract
from PIL import Image, ImageDraw
import pyautogui
import os

# Укажем путь к tessdata (если нужно)

# Coordinates of the region: (left, top, width, height)
region = (1, 1200, 3600, 200)

# Take a full screenshot (not cropped yet)
full_screenshot = pyautogui.screenshot()

# Draw highlight rectangle on the full screenshot
draw = ImageDraw.Draw(full_screenshot)
x, y, w, h = region

draw.rectangle([x, y, x + w, y + h], outline="red", width=5)  # red border
full_screenshot.save("highlighted.png")

# Also crop only the region for OCR
screenshot = pyautogui.screenshot(region=region)
screenshot.save("zone.png")

# OCR in Russian
text = pytesseract.image_to_string(screenshot, lang="eng")

print("Detected text:")
print(text)
