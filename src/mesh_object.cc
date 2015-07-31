#include "mesh_object.h"

MeshObject::MeshObject() {

}

MeshObject::MeshObject(Mesh &mesh, Material &material) {
    mesh_ = mesh;
    material_ = material;

    material_.SetMesh(mesh_);

    transform = Transform();

    x_ = 0;
    y_ = 0;
    z_ = 0;
    s_ = 1;
}

void MeshObject::Update(float delta_time) {
    // x_ +=  1.0f * delta_time;
    y_ +=  0.8f * delta_time;
    // z_ += -0.1f * delta_time;
    transform.SetRotation(x_, y_, z_);

    // s_ += 0.0001f;
    // scale_ = glm::scale(s_, s_, s_);
}

void MeshObject::Render(const Camera &camera, const Light &light) const {
    // transform.GetModelMatrix();
    material_.Render(camera, light, transform.GetModelMatrix());
}

void MeshObject::Cleanup() {

}
