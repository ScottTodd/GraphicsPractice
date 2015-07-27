#include <iostream>

#include "scene.h"

int main(void) {
    Scene scene = Scene();

    bool success = scene.Initialize();
    if (!success) { return 0; }
    std::cout << "Scene initialized.\n";

    scene.InitializeObjects();
    std::cout << "Objects inititlized.\n";

    do {
        scene.Update();
        scene.Render();
    } while(scene.is_running);

    scene.Cleanup();

    return 0;
}
