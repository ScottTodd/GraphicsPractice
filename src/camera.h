#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(float fov = 60.0f,
           float aspect_ratio = 1.33333f,
           float near_clip = 0.f,
           float far_clip = 100.0f,
           glm::vec3 position = glm::vec3(0,0,10),
           glm::vec3 target = glm::vec3(0,0,0),
           glm::vec3 up = glm::vec3(0,1,0));

    glm::mat4 TransformModel(glm::mat4 model);

private:
    glm::mat4 projection;
    glm::mat4 view;
};

#endif // CAMERA_H
