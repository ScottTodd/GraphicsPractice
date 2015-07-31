#ifndef MESH_OBJECT_H
#define MESH_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

#include "camera.h"
#include "light.h"
#include "material.h"
#include "mesh.h"
#include "renderable.h"

class MeshObject : public Renderable {
public:
    MeshObject();
    MeshObject(Mesh &mesh, Material &material);

    ~MeshObject() {}

    void Update(float delta_time);
    void Render(const Camera &camera, const Light &light) const;
    void Cleanup();

private:
    Mesh mesh_;

    glm::mat4 translation_;
    glm::quat rotation_;
    glm::mat4 scale_;

    float x_;
    float y_;
    float z_;
    float s_;
};

#endif // MESH_OBJECT_H
