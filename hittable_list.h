#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <vector>
#include <memory>

using std::make_shared;
using std::shared_ptr;

class hittable_list //: public hittable
{
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void add(shared_ptr<hittable> object)
    {
        objects.push_back(object);
    }
    void clear() { objects.clear(); }

    bool hit(const ray&r, double ray_tmin, double ray_tmax , hit_record& rec) const
    {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for(const auto& object: objects)
        {
            // if temp_rec has been updated to a closer hit, then update rec to it
            if(object->hit(r, ray_tmin, closest_so_far, temp_rec))
            {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;                
            }
        }

        return hit_anything;
    }
};

#endif