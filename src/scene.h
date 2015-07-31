#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "camera.h"
#include "renderable.h"
#include "light.h"

class Scene {
public:
    Scene();

    bool Initialize();
    void Cleanup();

    // Takes ownership by wraping in std::unique_ptr.
    // TODO: refactor once ownership rules are better defined?
    void AddObject(Renderable* scene_object);

    void Update();
    void Render();

    bool is_running;

private:
    GLFWwindow* window_;
    std::vector<std::unique_ptr<Renderable>> scene_objects_;
    Camera camera_;
    Light light_;

    double last_time_;
};

#endif // SCENE_H
