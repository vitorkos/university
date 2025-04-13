import numpy as np
from PIL import Image
from scipy.ndimage import convolve
import math
from src.imp.noise_reduction_and_smoothing import gaussian_kernel, gaussian_blur


def canny_edge_detection(img, lowThreshold, highThreshold):
    kernel = gaussian_kernel(5, sigma=1)
    gauss = gaussian_blur(img, kernel)

    magnitude, angle = sobel_filters(gauss)

    nms = non_maximum_suppression(magnitude, angle)

    thresh_img, weak, strong = threshold(nms, lowThreshold, highThreshold)
    result = hysteresis(thresh_img, weak, strong)

    return Image.fromarray(result.astype(np.uint8))


def sobel_filters(image):
    Kx = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]], dtype=np.float32)
    Ky = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]], dtype=np.float32)

    Ix = convolve(image, Kx)
    Iy = convolve(image, Ky)

    magnitude = np.hypot(Ix, Iy)
    magnitude = magnitude / magnitude.max() * 255
    angle = np.arctan2(Iy, Ix)

    return magnitude, angle

def non_maximum_suppression(magnitude, angle):
    Z = np.zeros_like(magnitude)
    angle = angle * 180. / np.pi
    angle[angle < 0] += 180

    rows, cols = magnitude.shape
    for i in range(1, rows-1):
        for j in range(1, cols-1):
            q = 255
            r = 255

            direction = angle[i, j]

            if (0 <= direction < 22.5) or (157.5 <= direction <= 180):
                q = magnitude[i, j+1]
                r = magnitude[i, j-1]
            elif (22.5 <= direction < 67.5):
                q = magnitude[i+1, j-1]
                r = magnitude[i-1, j+1]
            elif (67.5 <= direction < 112.5):
                q = magnitude[i+1, j]
                r = magnitude[i-1, j]
            elif (112.5 <= direction < 157.5):
                q = magnitude[i-1, j-1]
                r = magnitude[i+1, j+1]

            if magnitude[i, j] >= q and magnitude[i, j] >= r:
                Z[i, j] = magnitude[i, j]
            else:
                Z[i, j] = 0
    return Z

def threshold(image, lowThreshold, highThreshold):
    strong = 255
    weak = 75

    strong_i, strong_j = np.where(image >= highThreshold)
    weak_i, weak_j = np.where((image >= lowThreshold) & (image < highThreshold))

    result = np.zeros_like(image)
    result[strong_i, strong_j] = strong
    result[weak_i, weak_j] = weak

    return result, weak, strong

def hysteresis(image, weak, strong=255):
    rows, cols = image.shape
    for i in range(1, rows-1):
        for j in range(1, cols-1):
            if image[i, j] == weak:
                if np.any(image[i-1:i+2, j-1:j+2] == strong):
                    image[i, j] = strong
                else:
                    image[i, j] = 0
    return image