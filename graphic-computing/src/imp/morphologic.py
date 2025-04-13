import numpy as np
from PIL import Image

def erode(image, kernel_size=3):
    img_array = np.array(image.convert('L'))  # converte para escala de cinza
    thresholded = (img_array > 127).astype(np.uint8)  # binariza a imagem

    pad = kernel_size // 2
    padded = np.pad(thresholded, pad, mode='constant', constant_values=0)
    output = np.zeros_like(thresholded)

    for i in range(pad, padded.shape[0] - pad):
        for j in range(pad, padded.shape[1] - pad):
            region = padded[i - pad:i + pad + 1, j - pad:j + pad + 1]
            if np.all(region == 1):
                output[i - pad, j - pad] = 255  # mantém branco
            else:
                output[i - pad, j - pad] = 0    # vira preto

    return Image.fromarray(output.astype(np.uint8))