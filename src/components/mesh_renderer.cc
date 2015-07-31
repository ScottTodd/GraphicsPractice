#include "mesh_renderer.h"

#include "camera.h"
#include "light.h"
#include "scene.h"
#include "scene_object.h"

MeshRenderer::MeshRenderer() {

}

MeshRenderer::MeshRenderer(Mesh &mesh, Material &material) {
    mesh_ = mesh;
    material_ = material;

    material_.SetMesh(mesh_);
}

void MeshRenderer::Update(float delta_time) {

}

void MeshRenderer::Render() const {
    material_.Render(scene_object->scene->camera,
                     scene_object->scene->light,
                     scene_object->transform.GetModelMatrix());
}

void MeshRenderer::Cleanup() {

}
