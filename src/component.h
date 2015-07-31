#ifndef COMPONENT_H
#define COMPONENT_H

class SceneObject;
class Scene;

class Component {
public:
    Component() {}

    ~Component() {}

    virtual void Update(float delta_time) = 0;
    virtual void Render() const = 0;
    virtual void Cleanup() = 0;

    SceneObject* scene_object;
};

#endif // COMPONENT_H
