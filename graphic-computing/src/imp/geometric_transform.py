import numpy as np
from PIL import Image


def bilinear_interpolation_resize(image, new_width, new_height):
    original = np.array(image)
    orig_height, orig_width = original.shape[:2]

    if image.mode == 'L':
        channels = 1
    else:
        channels = original.shape[2]

    resized = np.zeros((new_height, new_width, channels), dtype=np.uint8)

    x_ratio = (orig_width - 1) / (new_width - 1) if new_width > 1 else 0
    y_ratio = (orig_height - 1) / (new_height - 1) if new_height > 1 else 0

    for i in range(new_height):
        for j in range(new_width):
            x_l = int(x_ratio * j)
            y_t = int(y_ratio * i)

            x_h = min(x_l + 1, orig_width - 1)
            y_b = min(y_t + 1, orig_height - 1)

            x_weight = (x_ratio * j) - x_l
            y_weight = (y_ratio * i) - y_t

            if channels == 1:
                a = original[y_t, x_l]
                b = original[y_t, x_h]
                c = original[y_b, x_l]
                d = original[y_b, x_h]

                pixel = (a * (1 - x_weight) * (1 - y_weight) +
                         b * x_weight * (1 - y_weight) +
                         c * (1 - x_weight) * y_weight +
                         d * x_weight * y_weight)
                resized[i, j] = int(pixel)
            else:
                for c in range(channels):
                    a = original[y_t, x_l, c]
                    b = original[y_t, x_h, c]
                    c_ = original[y_b, x_l, c]
                    d = original[y_b, x_h, c]

                    pixel = (a * (1 - x_weight) * (1 - y_weight) +
                             b * x_weight * (1 - y_weight) +
                             c_ * (1 - x_weight) * y_weight +
                             d * x_weight * y_weight)
                    resized[i, j, c] = int(pixel)

    if channels == 1:
        return Image.fromarray(resized[:, :, 0], mode='L')
    else:
        return Image.fromarray(resized)