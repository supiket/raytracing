cmake_minimum_required(VERSION 3.22)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracing main.cpp color.h ray.h vector3.h sphere.h scene_object.h)
