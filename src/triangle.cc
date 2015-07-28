#include "triangle.h"

#include "camera.h"
#include "material.h"

Triangle::Triangle() {

}

Triangle::Triangle(Material material) {
    material_ = material;
}

void Triangle::Update() {

}

void Triangle::Render(Camera camera) {
    material_.Render(camera);
}

void Triangle::Cleanup() {

}
