#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "material.h"
#include "mesh.h"
#include "mesh_renderer.h"
#include "scene_object.h"
#include "scene.h"

int main(void) {
    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    SceneObject* tetrahedron = new SceneObject();



    Material tetrahedron_mat = Material("BasicShading.vertexshader",
                                        "BasicShading.fragmentshader");

    std::vector<float> tetrahedron_vertices = {
        -1.0f,  0.0f, -0.707f,
         1.0f,  0.0f, -0.707f,
         0.0f,  1.0f,  0.707f,
         0.0f, -1.0f,  0.707f
    };
    std::vector<float> tetrahedron_normals = {
        -0.707f,  0.0f  , -0.707f,
         0.707f,  0.0f  , -0.707f,
         0.0f  ,  0.707f, 0.707f,
         0.0f  , -0.707f, 0.707f
    };
    std::vector<unsigned int> tetrahedron_indices = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 2, 1
    };
    Mesh tetrahedron_mesh = {tetrahedron_vertices,
                             tetrahedron_normals,
                             tetrahedron_indices};

    MeshRenderer* tetrahedron_renderer = new MeshRenderer(tetrahedron_mesh,
                                                          tetrahedron_mat);
    tetrahedron->AddComponent(tetrahedron_renderer);

    tetrahedron->transform.Translate(0, -1, 0);
    scene.AddObject(tetrahedron);

    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
