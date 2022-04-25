#include <iostream>
#include <fstream>
#include <DirectXMath.h>
#include "color.h"

int main() {
    std::ofstream image;
    image.open("../image.ppm", std::ios::out);
    if (image.is_open()) {

        const int image_width = 1000;
        const int image_height = 1000;

        image << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = image_height - 1; j >= 0; --j) {
            std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                DirectX::XMFLOAT3 pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
                write_color(image, pixel_color);
            }
        }
        std::cout << "\nDone.\n";

        image.close();
    }

    return 0;

}
