import math
import numpy as np
from PIL import Image

def gaussian_blur(image, kernel):
    image_array = np.array(image.convert('L'), dtype=np.float32)
    padded_image = np.pad(image_array, kernel.shape[0] // 2, mode='edge')
    output = np.zeros_like(image_array)

    k = kernel.shape[0] // 2

    for i in range(image_array.shape[0]):
        for j in range(image_array.shape[1]):
            region = padded_image[i:i + 2*k + 1, j:j + 2*k + 1]
            output[i, j] = np.sum(region * kernel)

    output = np.clip(output, 0, 255).astype(np.uint8)
    return Image.fromarray(output)


def gaussian_kernel(size, sigma=1):
    kernel = np.zeros((size, size), dtype=np.float32)
    center = size // 2

    for x in range(size):
        for y in range(size):
            dx = x - center
            dy = y - center
            kernel[x, y] = math.exp(-(dx**2 + dy**2) / (2 * sigma**2))

    kernel /= np.sum(kernel)
    return kernel
