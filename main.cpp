#include <iostream>
#include <fstream>
#include <DirectXMath.h>
#include <vector>
#include "color.h"
#include "ray.h"
#include "vector3.h"
#include "sphere.h"

DirectX::XMFLOAT3 ray_color(const ray &r) {
    hit temp_rec;
    if (sphere(DirectX::XMFLOAT3(0, 0, -1), 20, DirectX::XMFLOAT3(1, 0, 0)).hit(r, 0, 100, temp_rec))
        return DirectX::XMFLOAT3(1, 0, 0);

    DirectX::XMFLOAT3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * DirectX::XMFLOAT3(1.0, 1.0, 1.0) +
           t * DirectX::XMFLOAT3(0.5, 0.7, 1.0);
}

int main() {
    const int image_width = 1000;
    const int image_height = 1000;

    DirectX::XMFLOAT3 center = DirectX::XMFLOAT3(0, 0, 100);
    auto viewport_width = 100;
    auto viewport_height = 100;
    auto near_plane = 200;
    auto far_plane = 1000;
    auto focal_length = 100;

    DirectX::XMFLOAT3 eye_point = DirectX::XMFLOAT3(0, 0, 0);
    DirectX::XMFLOAT3 horizontal = DirectX::XMFLOAT3(viewport_width, 0, 0);
    DirectX::XMFLOAT3 vertical = DirectX::XMFLOAT3(0, viewport_height, 0);
    DirectX::XMFLOAT3 lower_left_corner =
            center - horizontal / 2 - vertical / 2 - DirectX::XMFLOAT3(0, 0, focal_length);

    DirectX::XMFLOAT3 light = DirectX::XMFLOAT3(500, 500, 500);

    /*
    int num_spheres;

    std::cout << "Enter the number of spheres: ";
    std::cin >> num_spheres;

    std::vector<sphere> spheres;

    for (int i = 0; i < num_spheres; i++) {
        int x, y, z, radius, r, g, b;
        std::cout << "Enter the origin of sphere " << (i + 1) << " in the form X Y Z: ";
        std::cin >> x >> y >> z;
        std::cout << "Enter the radius of sphere " << (i + 1) << ": ";
        std::cin >> radius;
        std::cout << "Enter the color of sphere " << (i + 1) << " in the form R G B: ";
        std::cin >> r >> g >> b;
        spheres.push_back(sphere(DirectX::XMFLOAT3(x, y, z), radius, DirectX::XMFLOAT3(r, g, b)));
    }
    */


    std::ofstream image;
    image.open("../image.ppm", std::ios::out);

    if (image.is_open()) {
        image << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = image_height - 1; j >= 0; --j) {
            std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                auto u = double(i) / (image_width - 1);
                auto v = double(j) / (image_height - 1);
                ray r(center, lower_left_corner + u * horizontal + v * vertical - center);
                DirectX::XMFLOAT3 pixel_color = ray_color(r);
                write_color(image, pixel_color);
            }
        }
        std::cout << "\nDone.\n";

        image.close();
    }

    return 0;

}
