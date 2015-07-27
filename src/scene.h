#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

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
    GLuint program_id;
    GLuint matrix_id;
    GLuint vertexbuffer;
    GLuint vertex_array_id;
    glm::mat4 mvp;
};

#endif
