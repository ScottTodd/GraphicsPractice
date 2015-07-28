#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "camera.h"

class Renderable
{
public:
    virtual ~Renderable() {}

    virtual void Update() = 0;
    virtual void Render(Camera camera) = 0;
    virtual void Cleanup() = 0;
};

#endif // RENDERABLE_H
