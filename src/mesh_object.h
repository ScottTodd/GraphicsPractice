#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include "camera.h"
#include "light.h"
#include "material.h"
#include "mesh.h"
#include "renderable.h"
#include "transform.h"

class MeshObject : public Renderable {
public:
    MeshObject();
    MeshObject(Mesh &mesh, Material &material);

    ~MeshObject() {}

    void Update(float delta_time);
    void Render(const Camera &camera, const Light &light) const;
    void Cleanup();

    Transform transform;

private:
    Mesh mesh_;

    float x_;
    float y_;
    float z_;
};

#endif // MESH_OBJECT_H
