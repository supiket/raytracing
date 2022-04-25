#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include <DirectXMath.h>
#include "scene_object.h"
#include "vector3.h"

class sphere : public scene_object {
public:
    DirectX::XMFLOAT3 origin;
    int radius;
    DirectX::XMFLOAT3 color;

    sphere() {}

    sphere(const DirectX::XMFLOAT3 &origin, const int radius, const DirectX::XMFLOAT3 &color) {
        this->origin = origin;
        this->radius = radius;
        this->color = color;
    }

    virtual bool hit(
            const ray &r, double t_min, double t_max, struct hit &hit) const override;

};

bool sphere::hit(const ray &r, double t_min, double t_max, struct hit &rec) const {
    DirectX::XMFLOAT3 oc = r.origin() - origin;
    DirectX::XMFLOAT3 dir = r.direction();
    double a = length_squared(dir);
    double half_b = dot(oc, r.direction());
    double c = length_squared(oc) - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - origin) / radius;

    return true;
}


#endif
