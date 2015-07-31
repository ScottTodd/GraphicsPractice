#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include <memory>
#include <vector>

#include "component.h"
#include "transform.h"

class Scene;

class SceneObject {
public:
    SceneObject();

    ~SceneObject() {}

    void Update(float delta_time);
    void Render() const;
    void Cleanup();

    void AddComponent(Component* component);

    template<class T>             T  GetComponent();
    template<class T> std::vector<T> GetComponents();

    Transform transform;

    Scene* scene;

private:
    std::vector<std::unique_ptr<Component>> components_;
};

#endif // SCENE_OBJECT_H
