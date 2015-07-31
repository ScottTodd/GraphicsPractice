#include "transform.h"

#include <glm/gtx/transform.hpp>

Transform::Transform() {
    position = glm::vec3(0, 0, 0);
    rotation = glm::quat(glm::vec3(0, 0, 0));
    scale = glm::vec3(1, 1, 1);
}

glm::mat4 Transform::GetTranslationMatrix() const {
    return glm::translate(position);
}

glm::mat4 Transform::GetRotationMatrix() const {
    return glm::mat4_cast(rotation);
}

glm::mat4 Transform::GetScaleMatrix() const {
    return glm::scale(scale);
}

glm::mat4 Transform::GetModelMatrix() const {
    return GetTranslationMatrix() * GetRotationMatrix() * GetScaleMatrix();
}

void Transform::SetRotation(glm::vec3 euler_angles) {
    rotation = glm::quat(euler_angles);
}

void Transform::SetRotation(float x, float y, float z) {
    SetRotation(glm::vec3(x, y, z));
}

void Transform::Translate(glm::vec3 translation) {
    position += translation;
}

void Transform::Translate(float x, float y, float z) {
    Translate(glm::vec3(x, y, z));
}
