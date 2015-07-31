#include "mesh_renderer.h"

#include "camera.h"
#include "light.h"
#include "scene.h"

MeshRenderer::MeshRenderer() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

MeshRenderer::MeshRenderer(Mesh &mesh, Material &material) {
    mesh_ = mesh;
    material_ = material;

    material_.SetMesh(mesh_);

    x_ = 0;
    y_ = 0;
    z_ = 0;
}

void MeshRenderer::Update(float delta_time) {
    // x_ +=  1.0f * delta_time;
    y_ +=  0.8f * delta_time;
    // z_ += -0.1f * delta_time;
    scene_object->transform.SetRotation(x_, y_, z_);
}

void MeshRenderer::Render() const {
    material_.Render(scene_object->scene->camera,
                     scene_object->scene->light,
                     scene_object->transform.GetModelMatrix());
}

void MeshRenderer::Cleanup() {

}
