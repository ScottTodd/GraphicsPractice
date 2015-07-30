#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "camera.h"
#include "light.h"
#include "material.h"
#include "renderable.h"

class Triangle : public Renderable
{
public:
    Triangle();
    Triangle(Material material);

    ~Triangle() {}

    void Update();
    void Render(Camera camera, Light light);
    void Cleanup();
};

#endif // TRIANGLE_H
