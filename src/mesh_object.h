#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include "camera.h"
#include "light.h"
#include "material.h"
#include "mesh.h"
#include "renderable.h"

class MeshObject : public Renderable
{
public:
    MeshObject();
    MeshObject(Mesh &mesh, Material &material);

    ~MeshObject() {}

    void Update();
    void Render(const Camera &camera, const Light &light) const;
    void Cleanup();

private:
    Mesh mesh_;
};

#endif // MESH_OBJECT_H
