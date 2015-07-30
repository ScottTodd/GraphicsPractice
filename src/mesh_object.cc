#include "mesh_object.h"

#include <vector>

#include <GL/glew.h>

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
}

void MeshObject::Update() {

}

void MeshObject::Render(const Camera &camera, const Light &light) const {
    material_.Render(camera, light);
}

void MeshObject::Cleanup() {

}
