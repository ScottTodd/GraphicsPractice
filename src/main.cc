#include <iostream>
#include <stdlib.h>
#include <vector>

#include <glm/glm.hpp>

#include "components/mesh_renderer.h"
#include "components/rotate.h"
#include "material.h"
#include "mesh.h"
#include "scene_object.h"
#include "scene.h"

int main(void) {
    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    for (int i = 0; i < 10; ++i) {
        SceneObject* tetrahedron = new SceneObject();
        tetrahedron->transform.position = glm::vec3(rand() % 8 - 4,
                                                    rand() % 8 - 4,
                                                    rand() % 8 - 4);

        Material tetrahedron_mat = Material(
                "shaders/BasicShading.vertexshader",
                "shaders/BasicShading.fragmentshader");

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

        tetrahedron->AddComponent(new Rotate(rand() % 2 - 1.0f,
                                             rand() % 2 - 1.0f,
                                             rand() % 2 - 1.0f));

        tetrahedron->transform.Translate(0, -1, 0);
        scene.AddObject(tetrahedron);
    }

    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
