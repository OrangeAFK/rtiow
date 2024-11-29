#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera
{
public:
    double aspect_ratio = 1.0; // image width/height
    int image_width = 100; // image width in pixel count
    int samples_per_pixel = 10; // random samples per pixel
    int max_depth = 10; // max recursion for bounces
    void render(const hittable& world)
    {
        initialize();
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; i++) {
                vec3 pixel_color(0,0,0);
                for(int sample = 0; sample < samples_per_pixel; sample++)
                {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                }
                write_color(std::cout, pixel_samples_scale * pixel_color);
            }
        }
        std::clog << "\rDone.                   \n";
    }

private:
    int image_height;
    double pixel_samples_scale; // color scale factor for a sum of pixel samples
    vec3 center, pixel00_loc, pixel_delta_u, pixel_delta_v;
    void initialize()
    {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        pixel_samples_scale = 1.0 / samples_per_pixel;

        // Camera
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (double(image_width)/image_height);
        auto center = vec3(0,0,0);

        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        // pixel to pixel distances
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // calculate location of upper-left pixel 
        auto viewport_upper_left = center - vec3(0,0,focal_length) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v); 
    }

    ray get_ray(int i, int j) const
    {
        // construct a camera ray starting at the origin and directed at randomly sampled point around i,j
        auto offset = sample_square();
        auto pixel_sample = pixel00_loc + ((i+offset.x()) * pixel_delta_u) + ((j+offset.y()) * pixel_delta_v);
        auto ray_origin = center;
        auto ray_dir = pixel_sample - ray_origin;
        return ray(ray_origin, ray_dir);
    }

    vec3 sample_square() const
    {
        // returns vector to a random point in the unit square [-.5, .5]
        return vec3(random_double() - 0.5, random_double() - 0.5, 0);

    }

    vec3 ray_color(const ray& r, int depth, const hittable& world) const
    {
        if(depth<=0) { return vec3(0,0,0); }
        hit_record rec;
        // world objects colored by normals
        if(world.hit(r, interval(0.001, infinity), rec))
        {
            vec3 direction = rec.normal + random_unit_vector();
            return 0.5 * ray_color(ray(rec.p, direction), depth-1, world);
        }

        // background, white/blue gradient
        vec3 unit_dir = unit_vector(r.direction());
        auto a = 0.5 * (unit_dir.y() + 1.0); // a: [-1,-1] -> [0,1]
        return (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);

    }
};

#endif