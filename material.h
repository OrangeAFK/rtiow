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
    metal(const vec3& albedo, double fuzz) : albedo(albedo), fuzz(fuzz<1 ? fuzz : 1) {}
    bool scatter(
    const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered
    ) const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        reflected = unit_vector(reflected) + (fuzz * random_unit_vector()); // fuzz
        scattered = ray(rec.p, reflected);
        attenuation = albedo; 
        return (dot(scattered.direction(), rec.normal) > 0);
    }
private:
    vec3 albedo;
    double fuzz;
};

class dielectric : public material
{
public:
    dielectric(double refraction_index) : refraction_index(refraction_index) {}
    bool scatter(
    const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered
    ) const override {
        attenuation = vec3(1.0,1.0,1.0);
        double ri = rec.front_face ? (1.0/refraction_index) : refraction_index;
        
        vec3 unit_direction = unit_vector(r_in.direction());
        double cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);
        
        bool cannot_refract = (ri * sin_theta) > 1.0;
        vec3 direction;
        if(cannot_refract)
        {
            direction = reflect(unit_direction, rec.normal);
        }
        else
        {
            direction = refract(unit_direction, rec.normal, ri);
        }
        
        scattered = ray(rec.p, direction);
        return true;
    }
private:
    double refraction_index; // Snell's law coefficient
};

#endif