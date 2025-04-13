from PIL import Image

from src.imp.edge_detection_and_enhancement_filter import canny_edge_detection
from src.imp.geometric_transform import bilinear_interpolation_resize
from src.imp.intensity_highlight_adjustment import contrast_highlight
from src.imp.morphologic import erode
from src.imp.noise_reduction_and_smoothing import gaussian_kernel, gaussian_blur

if __name__ == "__main__":

    path = r"../raw/gmi.jpg"
    img = Image.open(path)
    img = img.convert("RGB")

    #contrast_img = contrast_highlight(img, 1.5)
    #kernel = gaussian_kernel(size=5, sigma=1.0)
    #blurred_img = gaussian_blur(img, kernel)
    #canny = canny_edge_detection(img,lowThreshold = 200,highThreshold = 250)
    #inter = bilinear_interpolation_resize(img, 50, 50)
    er = erode(img, kernel_size=3)



    #contrast_img.show()
    #blurred_img.show()
    #canny.show()
    #inter.show()
    er.show()