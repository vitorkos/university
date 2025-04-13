import os
from PIL import Image

from src.imp.edge_detection_and_enhancement_filter import canny_edge_detection
from src.imp.geometric_transform import bilinear_interpolation_resize
from src.imp.intensity_highlight_adjustment import contrast_highlight
from src.imp.morphologic import erode
from src.imp.noise_reduction_and_smoothing import gaussian_kernel, gaussian_blur

if __name__ == "__main__":

    input_path = r"../raw/gmi.jpg"
    output_dir = "../../processed"
    os.makedirs(output_dir, exist_ok=True)

    img = Image.open(input_path)
    img = img.convert("RGB")

    contrast_img = contrast_highlight(img, 1.5)
    contrast_img.save(os.path.join(output_dir, "contrast_img.jpg"))

    kernel = gaussian_kernel(size=5, sigma=1.0)
    blurred_img = gaussian_blur(img, kernel)
    blurred_img.save(os.path.join(output_dir, "blurred_img.jpg"))

    canny = canny_edge_detection(img, lowThreshold=200, highThreshold=250)
    canny.save(os.path.join(output_dir, "canny_edges.jpg"))

    inter = bilinear_interpolation_resize(img, 50, 50)
    inter.save(os.path.join(output_dir, "resized_bilinear.jpg"))

    er = erode(img, kernel_size=3)
    er.save(os.path.join(output_dir, "eroded.jpg"))

