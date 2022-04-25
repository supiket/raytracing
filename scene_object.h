#ifndef RAYTRACING_SCENE_OBJECT_H
#define RAYTRACING_SCENE_OBJECT_H

#include "ray.h"

struct hit {
    DirectX::XMFLOAT3 p;
    DirectX::XMFLOAT3 normal;
    double t;
};

class scene_object {
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit &hit) const = 0;
};

#endif
