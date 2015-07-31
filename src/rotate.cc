#include "rotate.h"

#include <glm/gtc/quaternion.hpp>

#include "scene_object.h"

Rotate::Rotate() {
    axis_speeds = glm::vec3(0, 0, 0);
}

Rotate::Rotate(glm::vec3 axis_speeds) {
    this->axis_speeds = axis_speeds;
}

Rotate::Rotate(float x, float y, float z) {
    axis_speeds = glm::vec3(x, y, z);
}

void Rotate::Update(float delta_time) {
    glm::quat rotation = glm::quat(axis_speeds * delta_time);
    scene_object->transform.rotation = (scene_object->transform.rotation *
                                        rotation);
}

void Rotate::Cleanup() {

}
