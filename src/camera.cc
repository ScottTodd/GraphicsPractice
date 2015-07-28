#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    projection = glm::perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    view = glm::lookAt(glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0));
}

Camera::Camera(float fov, float aspect_ratio, float near_clip, float far_clip) {
    projection = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
    view = glm::lookAt(glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0));

}

Camera::Camera(float fov, float aspect_ratio, float near_clip, float far_clip,
               glm::vec3 position, glm::vec3 target, glm::vec3 up) {
    projection = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
    view = glm::lookAt(position, target, up);
}

glm::mat4 Camera::TransformModel(glm::mat4 model) {
    return projection * view * model;
}
