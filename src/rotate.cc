#include "rotate.h"

#include <glm/glm.hpp>

#include "scene_object.h"

Rotate::Rotate() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

void Rotate::Update(float delta_time) {
    // x_ +=  1.0f * delta_time;
    y_ +=  0.8f * delta_time;
    // z_ += -0.1f * delta_time;
    scene_object->transform.SetRotation(x_, y_, z_);
}

void Rotate::Cleanup() {

}
