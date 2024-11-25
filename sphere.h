#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable
{
private:
    vec3 center;
    double radius;
public:
    sphere(const vec3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override
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
        if(discriminant<0) { return false; }

        // find the nearest root that lies within the acceptable range
        auto sqrtd = std::sqrt(discriminant);
        auto root = (h - sqrtd) / a;
        if(!ray_t.surrounds(root))
        {
            root = (h + sqrtd)/a;
            if(!ray_t.surrounds(root)) { return false; }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        
        return true;
    }
};

#endif