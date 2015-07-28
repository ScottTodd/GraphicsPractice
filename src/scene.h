#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "camera.h"
#include "renderable.h"

class Scene {
public:
    Scene();

    bool Initialize();
    void InitializeObjects();
    void Cleanup();

    void Update();
    void Render();

    bool is_running;

private:
    GLFWwindow* window_;
    std::vector<std::unique_ptr<Renderable>> scene_objects_;
    Camera camera_;
};

#endif // SCENE_H
