#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

double hit_sphere(const vec3& center, double radius, const ray& r)
{
    // sphere equation is (C_x - x^2) + (C_y - y^2) + (C_z - z^2) = r^2
    // -> (C-P)*(C-P) = (C-(Q+td))*(C-(Q+td)) = r^2 --> expand P to Q+td since equation is true when the ray satisfies that condition at some t
    // -> t^2*d*d - 2td*(C-Q) + [(C-Q)*(C-Q) - r^2] = 0
    // by quadratic formula, a = d*d, b = -2d*(C-Q), c = (C-Q)*(C-Q) - r^2
    // but let b = -2h --> h = d*(C-Q). Then the quadratic formula simplifies to:
    // t = (h +- sqrt(h^2 - ac))/ a
    vec3 oc = center - r.origin(); // C-Q
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = h*h - a*c;
    
    if (discriminant < 0)
    {
        return -1;
    }
    else
    {
        return (h - std::sqrt(discriminant))/a;
    }
}

vec3 ray_color(const ray& r)
{
    // ball with colored normals
    auto t = hit_sphere(vec3(0,0,-1), 0.5, r);
    if(t>0)
    {
        vec3 normal = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.5*vec3(normal.x()+1, normal.y()+1, normal.z()+1);
    }

    // white-blue gradient based on y-position
    vec3 unit_dir = unit_vector(r.direction());
    auto a = 0.5 *(unit_dir.y() + 1.0); // 0<=a<=1
    return (1.0-a)*vec3(1.0,1.0,1.0) + a*vec3(0.5,0.7,1.0);
}

int main() {

    // Image

    auto aspect_ratio = 16.0/9.0;
    int image_width = 400;

    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = vec3(0,0,0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // pixel to pixel distances
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // calculate location of upper-left pixel 
    auto viewport_upper_left = camera_center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v); 

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            auto pixel_color = ray_color(ray(camera_center, ray_direction));
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                   \n";
}