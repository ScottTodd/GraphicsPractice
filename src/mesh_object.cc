#include "mesh_object.h"

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

#include "camera.h"
#include "light.h"
#include "material.h"
#include "mesh.h"

MeshObject::MeshObject() {

}

MeshObject::MeshObject(Mesh &mesh, Material &material) {
    mesh_ = mesh;
    material_ = material;

    material_.SetMesh(mesh_);

    translation_ = glm::translate(0, 0, 0);
    rotation_ = glm::quat(glm::vec3(10, 10, 0));
    scale_ = glm::scale(1, 1, 1);

    x_ = 0;
    y_ = 0;
    z_ = 0;
    s_ = 1;
}

void MeshObject::Update() {
    x_ +=  0.0002f;
    y_ +=  0.00003f;
    z_ += -0.0003f;
    rotation_ = glm::quat(glm::vec3(x_, y_, z_));

    // s_ += 0.0001f;
    // scale_ = glm::scale(s_, s_, s_);
}

void MeshObject::Render(const Camera &camera, const Light &light) const {
    glm::mat4 rotation_matrix = glm::mat4_cast(rotation_);
    glm::mat4 model_transform = translation_ * rotation_matrix * scale_;
    material_.Render(camera, light, model_transform);
}

void MeshObject::Cleanup() {

}
