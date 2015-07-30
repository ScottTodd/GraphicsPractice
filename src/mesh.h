#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm/glm.hpp>

struct Mesh {
    std::vector<float> vertices;
    std::vector<int> indices;
};

#endif // MESH_H
