#include "transform.h"

Transform::Transform() {
    translation = glm::translate(0, 0, 0);
    rotation = glm::quat(glm::vec3(0, 0, 0));
    scale = glm::scale(1, 1, 1);
}

glm::mat4 Transform::GetRotationMatrix() const {
    return glm::mat4_cast(rotation);
}

glm::mat4 Transform::GetModelMatrix() const {
    return translation * GetRotationMatrix() * scale;
}

void Transform::SetRotation(glm::vec3 euler_angles) {
    rotation = glm::quat(euler_angles);
}

void Transform::SetRotation(float x, float y, float z) {
    SetRotation(glm::vec3(x, y, z));
}
