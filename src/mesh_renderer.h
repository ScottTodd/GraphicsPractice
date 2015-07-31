#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "component.h"
#include "material.h"
#include "mesh.h"
#include "scene_object.h"

class MeshRenderer : public Component {
public:
    MeshRenderer();
    MeshRenderer(Mesh &mesh, Material &material);

    ~MeshRenderer() {}

    void Update(float delta_time);
    void Render() const;
    void Cleanup();

private:
    Mesh mesh_;
    Material material_;

    float x_;
    float y_;
    float z_;
};

#endif // MESH_RENDERER_H
