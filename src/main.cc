#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtx/random.hpp>

#include "components/mesh_renderer.h"
#include "components/rotate.h"
#include "material.h"
#include "mesh.h"
#include "scene_object.h"
#include "scene.h"
#include "texture.h"

void AddCube(Scene &scene) {
    SceneObject* cube = new SceneObject();
    cube->transform.position = glm::vec3(glm::linearRand(-4.0f, 4.0f),
                                         glm::linearRand(-4.0f, 4.0f),
                                         glm::linearRand(-4.0f, 4.0f));

    Material cube_mat = Material(
            "shaders/BasicShading.vertexshader",
            "shaders/BasicShading.fragmentshader");

    Texture texture;
    texture.Load("resources/UVCheckerMaps/UVCheckerMap01-512.png");
    cube_mat.SetTexture(texture);

    std::vector<float> cube_vertices = {
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
         1.0f, 1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
         1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f, 1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
         1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f, 1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f, 1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
         1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
         1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
         1.0f,-1.0f, 1.0f
    };

    std::vector<float> cube_uvs = {
        0.000059f, 1.0f-0.000004f,
        0.000103f, 1.0f-0.336048f,
        0.335973f, 1.0f-0.335903f,
        1.000023f, 1.0f-0.000013f,
        0.667979f, 1.0f-0.335851f,
        0.999958f, 1.0f-0.336064f,
        0.667979f, 1.0f-0.335851f,
        0.336024f, 1.0f-0.671877f,
        0.667969f, 1.0f-0.671889f,
        1.000023f, 1.0f-0.000013f,
        0.668104f, 1.0f-0.000013f,
        0.667979f, 1.0f-0.335851f,
        0.000059f, 1.0f-0.000004f,
        0.335973f, 1.0f-0.335903f,
        0.336098f, 1.0f-0.000071f,
        0.667979f, 1.0f-0.335851f,
        0.335973f, 1.0f-0.335903f,
        0.336024f, 1.0f-0.671877f,
        1.000004f, 1.0f-0.671847f,
        0.999958f, 1.0f-0.336064f,
        0.667979f, 1.0f-0.335851f,
        0.668104f, 1.0f-0.000013f,
        0.335973f, 1.0f-0.335903f,
        0.667979f, 1.0f-0.335851f,
        0.335973f, 1.0f-0.335903f,
        0.668104f, 1.0f-0.000013f,
        0.336098f, 1.0f-0.000071f,
        0.000103f, 1.0f-0.336048f,
        0.000004f, 1.0f-0.671870f,
        0.336024f, 1.0f-0.671877f,
        0.000103f, 1.0f-0.336048f,
        0.336024f, 1.0f-0.671877f,
        0.335973f, 1.0f-0.335903f,
        0.667969f, 1.0f-0.671889f,
        1.000004f, 1.0f-0.671847f,
        0.667979f, 1.0f-0.335851f
    };

    std::vector<float> cube_normals;
    std::vector<unsigned int> cube_indices;

    Mesh cube_mesh = {cube_vertices,
                      cube_normals,
                      cube_uvs,
                      cube_indices};

    MeshRenderer* cube_renderer = new MeshRenderer(cube_mesh,
                                                   cube_mat);
    cube->AddComponent(cube_renderer);

    cube->AddComponent(new Rotate(glm::linearRand(-2.0f, 2.0f),
                                  glm::linearRand(-2.0f, 2.0f),
                                  glm::linearRand(-2.0f, 2.0f)));

    scene.AddObject(cube);
}

void AddTetrahedron(Scene &scene) {
    SceneObject* tetrahedron = new SceneObject();
    tetrahedron->transform.position = glm::vec3(
            glm::linearRand(-4.0f, 4.0f),
            glm::linearRand(-4.0f, 4.0f),
            glm::linearRand(-4.0f, 4.0f));
    float scale = glm::linearRand(1.0f, 1.5f);
    tetrahedron->transform.scale = glm::vec3(scale, scale, scale);

    Material tetrahedron_mat = Material(
            "shaders/BasicShading.vertexshader",
            "shaders/BasicShading.fragmentshader");

    Texture texture;
    texture.Load("resources/UVCheckerMaps/UVCheckerMap01-512.png");
    tetrahedron_mat.SetTexture(texture);

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
    std::vector<float> tetrahedron_uvs = {
        0, 0,
        0, 1,
        1, 1,
        1, 0
    };
    std::vector<unsigned int> tetrahedron_indices = {
        0, 2, 1,
        0, 3, 2,
        2, 3, 1,
        0, 1, 3
    };
    Mesh tetrahedron_mesh = {tetrahedron_vertices,
                             tetrahedron_normals,
                             tetrahedron_uvs,
                             tetrahedron_indices};

    MeshRenderer* tetrahedron_renderer = new MeshRenderer(tetrahedron_mesh,
                                                          tetrahedron_mat);
    tetrahedron->AddComponent(tetrahedron_renderer);

    tetrahedron->AddComponent(new Rotate(glm::linearRand(-2.0f, 2.0f),
                                         glm::linearRand(-2.0f, 2.0f),
                                         glm::linearRand(-2.0f, 2.0f)));

    scene.AddObject(tetrahedron);
}

int main(void) {
    std::srand((unsigned int)std::time(0)); // Seed RNG.

    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    for (int i = 0; i < 5; ++i) {
        AddCube(scene);
        AddTetrahedron(scene);
    }

    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
