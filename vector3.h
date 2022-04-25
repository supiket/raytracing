#ifndef RAYTRACING_VECTOR3_H
#define RAYTRACING_VECTOR3_H

#include <cmath>
#include <DirectXMath.h>

double length_squared(DirectX::XMFLOAT3 &v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

double length(DirectX::XMFLOAT3 &v) {
    return std::sqrt(length_squared(v));
}

inline DirectX::XMFLOAT3 operator+(const DirectX::XMFLOAT3 &u, const DirectX::XMFLOAT3 &v) {
    return DirectX::XMFLOAT3(u.x + v.x, u.y + v.y, u.y + v.y);
}

inline DirectX::XMFLOAT3 operator-(const DirectX::XMFLOAT3 &u, const DirectX::XMFLOAT3 &v) {
    return DirectX::XMFLOAT3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline DirectX::XMFLOAT3 operator*(const DirectX::XMFLOAT3 &u, const DirectX::XMFLOAT3 &v) {
    return DirectX::XMFLOAT3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline DirectX::XMFLOAT3 operator*(double t, const DirectX::XMFLOAT3 &v) {
    return DirectX::XMFLOAT3(t * v.x, t * v.y, t * v.z);
}

inline DirectX::XMFLOAT3 operator*(const DirectX::XMFLOAT3 &v, double t) {
    return t * v;
}

inline DirectX::XMFLOAT3 operator/(DirectX::XMFLOAT3 v, double t) {
    return (1 / t) * v;
}


inline double dot(const DirectX::XMFLOAT3 &u, const DirectX::XMFLOAT3 &v) {
    return u.x * v.x
           + u.y * v.y
           + u.z * v.z;
}

inline DirectX::XMFLOAT3 cross(const DirectX::XMFLOAT3 &u, const DirectX::XMFLOAT3 &v) {
    return DirectX::XMFLOAT3(u.y * v.z - u.z * v.y,
                             u.z * v.x - u.x * v.z,
                             u.x * v.y - u.y * v.x);
}

inline DirectX::XMFLOAT3 unit_vector(DirectX::XMFLOAT3 v) {
    return v / length(v);
}

#endif
