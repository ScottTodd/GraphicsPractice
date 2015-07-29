#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspect_ratio, float near_clip, float far_clip,
               glm::vec3 position, glm::vec3 target, glm::vec3 up) {
    projection = glm::perspective(fov, aspect_ratio, near_clip, far_clip);
    view = glm::lookAt(position, target, up);
}
