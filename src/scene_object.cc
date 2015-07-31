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
