#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
    Transform();

    glm::mat4 translation;
    glm::quat rotation;
    glm::mat4 scale;

    glm::mat4 GetRotationMatrix() const;
    glm::mat4 GetModelMatrix() const;

    void SetRotation(glm::vec3 euler_angles);
    void SetRotation(float x, float y, float z);
};

#endif // TRANSFORM_H
