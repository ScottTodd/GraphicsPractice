#ifndef MESH_H
#define MESH_H

#include <vector>

// TODO: Convert to class, add CalculateNormals function/make normals optional.

struct Mesh {
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> uvs;
    std::vector<unsigned int> indices;
};

#endif // MESH_H
