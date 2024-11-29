#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class material
{
public:
    virtual ~material() = default;
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered
    ) const {
        return false;
    }
};

class lambertian : public material
{
public:
    lambertian(const vec3& albedo) : albedo(albedo) {}
    bool scatter(
    const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered
    ) const override {
        auto scatter_direction = rec.normal + random_unit_vector();
        // catch degenerate scatter direction ( random_unit_vector ~= -rec.normal, leading to infinities and NaNs)
        if(scatter_direction.near_zero()) { scatter_direction = rec.normal; }


        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo; 
        return true;
    }
private:
    vec3 albedo;
};

class metal : public material
{
public:
    metal(const vec3& albedo) : albedo(albedo) {}
    bool scatter(
    const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered
    ) const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo; 
        return true;
    }
private:
    vec3 albedo;
};

#endif