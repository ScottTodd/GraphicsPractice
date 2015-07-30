#include "triangle.h"

#include <vector>

#include <GL/glew.h>

#include "camera.h"
#include "light.h"
#include "material.h"

Triangle::Triangle() {

}

Triangle::Triangle(Material material) {
    material_ = material;

    std::vector<float> vertices = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };

    std::vector<int> indices = {0, 1, 2};

    material_.SetMesh(vertices, indices);
}

void Triangle::Update() {

}

void Triangle::Render(Camera camera, Light light) {
    material_.Render(camera, light);
}

void Triangle::Cleanup() {

}
