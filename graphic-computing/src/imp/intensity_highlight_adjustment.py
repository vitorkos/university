import numpy as np
from PIL import Image

def contrast_highlight(img, factor):
    width, height = img.size
    contrast_img = Image.new("RGB", (width, height))

    for x in range(height):
        for y in range(width):
            r, g, b = img.getpixel((x, y))

            r = int(128 + factor * (r - 128))
            g = int(128 + factor * (g - 128))
            b = int(128 + factor * (b - 128))

            r = max(0, min(255, r))
            g = max(0, min(255, g))
            b = max(0, min(255, b))

            contrast_img.putpixel((x, y), (r, g, b))

    return contrast_img