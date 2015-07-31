#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform {
public:
    Transform();

    // Representation.
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    // Matrices.
    glm::mat4 GetTranslationMatrix() const;
    glm::mat4 GetRotationMatrix() const;
    glm::mat4 GetScaleMatrix() const;
    glm::mat4 GetModelMatrix() const;

    // Convenience transformations/operators.
    void Translate(glm::vec3 translation);
    void Translate(float x, float y, float z);

    void SetRotation(glm::vec3 euler_angles);
    void SetRotation(float x, float y, float z);
};

#endif // TRANSFORM_H
