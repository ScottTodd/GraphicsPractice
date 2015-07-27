#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "renderable.h"

class Triangle : public Renderable
{
public:
    Triangle();

    ~Triangle() {}

    void Update();
    void Render();
    void Cleanup();
};

#endif // TRIANGLE_H
