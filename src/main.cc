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

    Material triangle_mat = Material("SimpleTransform.vertexshader",
                                     "BasicShading.fragmentshader");

    std::vector<float> triangle_vertices = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };
    std::vector<int> triangle_indices = {0, 1, 2};
    Mesh triangle_mesh = {triangle_vertices, triangle_indices};

    MeshObject* triangle = new MeshObject(triangle_mesh, triangle_mat);
    scene.AddObject(triangle);

    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
