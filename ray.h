#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
private:
    vec3 mOrigin;
    vec3 mDirection;
public:
    ray() {}
    ray(const vec3& origin, const vec3& direction) : mOrigin(origin), mDirection(direction) {}
    const vec3& origin() const {return mOrigin;}
    const vec3& direction() const {return mDirection;}
    vec3 at(double t) const {return mOrigin + t*mDirection;}
};

#endif