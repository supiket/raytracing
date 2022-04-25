#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include <DirectXMath.h>
#include <iostream>

void write_color(std::ostream &out, DirectX::XMFLOAT3 pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

#endif
