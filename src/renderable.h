#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable
{
public:
    virtual ~Renderable() {}

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;
};

#endif // RENDERABLE_H
