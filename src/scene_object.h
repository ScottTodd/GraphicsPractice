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

    template<class T>             T*  GetComponent();
    template<class T> std::vector<T*> GetComponents();

    Transform transform;

    Scene* scene;

private:
    std::vector<std::unique_ptr<Component>> components_;
};

template<class T> T* SceneObject::GetComponent() {
    for (int i = 0; i < components_.size(); ++i) {
        T* component = dynamic_cast<T*>(components_[i].get());
        if (component != NULL) {
            return component;
        }
    }
    return 0;
}

template<class T> std::vector<T*> SceneObject::GetComponents() {
    std::vector<T*> found_components;
    for (int i = 0; i < components_.size(); ++i) {
        T* component = dynamic_cast<T*>(components_[i].get());
        if (component != NULL) {
            found_components.push_back(component);
        }
    }
    return found_components;
}

#endif // SCENE_OBJECT_H
