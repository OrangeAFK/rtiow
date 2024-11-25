#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera
{
public:
    double aspect_ratio = 1.0; // image width/height
    int image_width = 100; // image width in pixel count
    void render(const hittable& world)
    {
        initialize();
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; i++) {
                auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                auto ray_direction = pixel_center - center;
                auto pixel_color = ray_color(ray(center, ray_direction), world);
                write_color(std::cout, pixel_color);
            }
        }
        std::clog << "\rDone.                   \n";
    }

private:
    int image_height;
    vec3 center, pixel00_loc, pixel_delta_u, pixel_delta_v;
    void initialize()
    {
        int image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        // Camera
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (double(image_width)/image_height);
        auto center = vec3(0,0,0);

        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        // pixel to pixel distances
        auto pixel_delta_u = viewport_u / image_width;
        auto pixel_delta_v = viewport_v / image_height;

        // calculate location of upper-left pixel 
        auto viewport_upper_left = center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
        auto pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v); 
    }
    vec3 ray_color(const ray& r, const hittable& world) const
    {
        hit_record rec;
        // world objects colored by normals
        if(world.hit(r, interval(0, infinity), rec))
        {
            return 0.5 * (rec.normal + vec3(1, 1, 1));
        }

        // background, white/blue gradient
        vec3 unit_dir = unit_vector(r.direction());
        auto a = 0.5 * (unit_dir.y() + 1.0); // a: [-1,-1] -> [0,1]
        return (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);

    }
};

#endif