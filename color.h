#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

void write_color(std::ostream& out, const vec3& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // translate [0, 1] components to [0, 255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // write out pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif