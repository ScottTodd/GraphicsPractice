#include <iostream>

#include "material.h"
#include "renderable.h"
#include "scene.h"
#include "triangle.h"

int main(void) {
    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    Material triangle_mat = Material("SimpleTransform.vertexshader",
                                     "BasicShading.fragmentshader");
    scene.AddObject(new Triangle(triangle_mat));
    std::cout << "Added objects to scene.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
