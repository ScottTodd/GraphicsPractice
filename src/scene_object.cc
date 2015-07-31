#include <scene_object.h>

SceneObject::SceneObject() {
    transform = Transform();
}

void SceneObject::Update(float delta_time) {
    for (int i = 0; i < components_.size(); ++i) {
        components_[i]->Update(delta_time);
    }
}

void SceneObject::Render() const {
    for (int i = 0; i < components_.size(); ++i) {
        components_[i]->Render();
    }
}

void SceneObject::Cleanup() {

}

void SceneObject::AddComponent(Component* component) {
    components_.push_back(std::unique_ptr<Component>(component));
    component->scene_object = this;
}

template<class T> T SceneObject::GetComponent() {
    for (int i = 0; i < components_.size(); ++i) {
        if (dynamic_cast<T>(&components_[i]) != NULL) {
            return &components_[i];
        }
    }
    return NULL;
}

template<class T> std::vector<T> SceneObject::GetComponents() {
    std::vector<T> found_components;
    for (int i = 0; i < components_.size(); ++i) {
        if (dynamic_cast<T>(&components_[i]) != NULL) {
            found_components.push_back(&components_[i]);
        }
    }
    return found_components;
}
