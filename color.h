#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

void write_color(std::ostream& out, const vec3& pixel_color)
{
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // translate [0, 1] components to [0, 255]
    static const interval intensity(0, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // write out pixel color components
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif