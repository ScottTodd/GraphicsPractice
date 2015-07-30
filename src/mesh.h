#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm/glm.hpp>

// TODO: Convert to class, add CalculateNormals function/make normals optional.

struct Mesh {
    std::vector<float> vertices;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;
};

#endif // MESH_H
