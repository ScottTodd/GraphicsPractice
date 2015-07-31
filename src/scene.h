#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

#include "camera.h"
#include "light.h"
#include "scene_object.h"

class Scene {
public:
    Scene();

    bool Initialize();
    void Cleanup();

    // Takes ownership by wraping in std::unique_ptr.
    // TODO: refactor once ownership rules are better defined?
    void AddObject(SceneObject* scene_object);

    void Update();
    void Render();

    bool is_running;

    Camera camera;
    Light light;

private:
    GLFWwindow* window_;
    std::vector<std::unique_ptr<SceneObject>> scene_objects_;

    double last_time_;
};

#endif // SCENE_H
