#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "camera.h"
#include "material.h"

class Renderable
{
public:
    Renderable() {}
    virtual ~Renderable() {}

    virtual void Update() = 0;
    virtual void Render(Camera camera) = 0;
    virtual void Cleanup() = 0;

protected:
    Material material_;
};

#endif // RENDERABLE_H
