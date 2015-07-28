#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
    Camera();
    Camera(float fov, float aspect_ratio, float near_clip, float far_clip);
    Camera(float fov, float aspect_ratio, float near_clip, float far_clip,
           glm::vec3 position, glm::vec3 target, glm::vec3 up);

    glm::mat4 TransformModel(glm::mat4 model);

private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif // CAMERA_H
