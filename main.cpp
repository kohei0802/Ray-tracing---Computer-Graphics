#include "Scene.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"
#include "Light.hpp"
#include "Renderer.hpp"

// In the main function of the program, we create the scene (create objects and lights)
// as well as set the options for the render (image width and height, maximum recursion
// depth, field-of-view, etc.). We then call the render function().
int main()
{
    Scene scene(1280, 960);

    // (center, radius)
    auto sph1 = std::make_unique<Sphere>(Vector3f(0, 0, -10), 1.5);
    sph1->materialType = DIFFUSE_AND_GLOSSY;
    sph1->diffuseColor = Vector3f(0.6, 0.7, 0.8);

    // (center, radius) 
    auto sph2 = std::make_unique<Sphere>(Vector3f(1.8, -0.3, -7.3), 1.25);
    sph2->ior = 1.5;
    sph2->materialType = REFLECTION_AND_REFRACTION;

    auto sph3 = std::make_unique<Sphere>(Vector3f(-2.7, 0, -12), 1.7);
    sph3->ior = 15.0;
    sph3->materialType = REFLECTION;

    scene.Add(std::move(sph1));
    scene.Add(std::move(sph2));
    scene.Add(std::move(sph3));

    Vector3f verts[4] = {{-5,-3,-6}, {5,-3,-6}, {5,-3,-16}, {-5,-3,-16}};
    uint32_t vertIndex[6] = {0, 1, 3, 1, 2, 3};
    Vector2f st[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    auto mesh = std::make_unique<MeshTriangle>(verts, vertIndex, 2, st);
    mesh->materialType = DIFFUSE_AND_GLOSSY;

    scene.Add(std::move(mesh));
    scene.Add(std::make_unique<Light>(Vector3f(-20, 70, 20), 0.5));
    scene.Add(std::make_unique<Light>(Vector3f(30, 50, -12), 0.5));    

    Renderer r;
    r.Render(scene);

    return 0;
}