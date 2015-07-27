#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

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
    GLFWwindow* window;

    std::vector<std::unique_ptr<Renderable>> scene_objects;

    GLuint program_id;
    GLuint matrix_id;
    GLuint vertexbuffer;
    GLuint vertex_array_id;
    glm::mat4 mvp;
};

#endif
