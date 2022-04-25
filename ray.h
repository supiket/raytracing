#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include <DirectXMath.h>
#include "vector3.h"

class ray {
public:
    ray() {}

    ray(const DirectX::XMFLOAT3 &origin, const DirectX::XMFLOAT3 &direction)
            : orig(origin), dir(direction) {}

    DirectX::XMFLOAT3 origin() const { return orig; }

    DirectX::XMFLOAT3 direction() const { return dir; }

    DirectX::XMFLOAT3 at(double t) const {
        return orig + t * dir;
    }

public:
    DirectX::XMFLOAT3 orig;
    DirectX::XMFLOAT3 dir;
};

#endif