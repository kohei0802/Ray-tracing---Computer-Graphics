#pragma once
#include "Scene.hpp"

struct hit_payload
{
    // hit location
    float tNear;
    uint32_t index;
    // barycentric 
    Vector2f uv;
    // what is hit
    Object* hit_obj;
};

class Renderer
{
public:
    void Render(const Scene& scene);

private:
};