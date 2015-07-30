#include <iostream>
#include <vector>

#include "material.h"
#include "mesh.h"
#include "mesh_object.h"
#include "renderable.h"
#include "scene.h"

int main(void) {
    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    Material tetrahedron_mat = Material("SimpleTransform.vertexshader",
                                        "BasicShading.fragmentshader");

    std::vector<float> tetrahedron_vertices = {
        -1.0f, -0.707f,  0.707f,
         1.0f, -0.707f,  0.707f,
         0.0f, -0.707f, -0.707f,
         0.0f,  0.707f,  0.0f
    };
    std::vector<unsigned int> tetrahedron_indices = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 2, 1
    };
    Mesh tetrahedron_mesh = {tetrahedron_vertices, tetrahedron_indices};

    MeshObject* tetrahedron = new MeshObject(tetrahedron_mesh, tetrahedron_mat);
    scene.AddObject(tetrahedron);

    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
