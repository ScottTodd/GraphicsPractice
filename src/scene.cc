#include "scene.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <common/shader.hpp>

#include "triangle.h"


Scene::Scene() {
    is_running = false;
}

bool Scene::Initialize() {
    // Initialise GLFW.
    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW.\n");
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context.
    window = glfwCreateWindow(1024, 768, "Graphics Practice", NULL, NULL);
    if(window == NULL){
        fprintf(stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW.
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW.\n");
        return false;
    }

    // Ensure we can capture the escape key to exit.
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    camera = Camera(60.0f, 4.0f / 3.0f, 0.1f, 100.0f,
                    glm::vec3(0,0,10), glm::vec3(0,0,0), glm::vec3(0,1,0));

    is_running = true;

    return true;
}

void Scene::InitializeObjects() {
    scene_objects.push_back(std::unique_ptr<Renderable>(new Triangle()));

    // TODO: Replace all of this with Renderable interface/class, Camera class.

    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);

    // Create and compile our GLSL program from the shaders
    program_id = LoadShaders("SimpleTransform.vertexshader",
                            "SingleColor.fragmentshader" );

    // Get a handle for our "MVP" uniform
    matrix_id = glGetUniformLocation(program_id, "MVP");

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
    };
    static const GLushort g_element_buffer_data[] = {0, 1, 2};

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
                 g_vertex_buffer_data, GL_STATIC_DRAW);
}

void Scene::Cleanup() {
    for (int i = 0; i < scene_objects.size(); ++i) {
        scene_objects[i]->Cleanup();
    }

    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteProgram(program_id);
    glDeleteVertexArrays(1, &vertex_array_id);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}

void Scene::Update() {
    for (int i = 0; i < scene_objects.size(); ++i) {
        scene_objects[i]->Update();
    }

    // Check if the ESC key was pressed or the window was closed
    is_running = (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
                  glfwWindowShouldClose(window) == 0);
}

void Scene::Render() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < scene_objects.size(); ++i) {
        scene_objects[i]->Render(camera);
    }

    // Use our shader
    glUseProgram(program_id);

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    // Model matrix : identity matrix (model will be at the origin)
    glm::mat4 mvp = camera.TransformModel(glm::mat4(1.0f));
    glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,        // attribute. Must match the layout in the shader.
        3,        // size
        GL_FLOAT, // type
        GL_FALSE, // normalized?
        0,        // stride
        (void*)0  // array buffer offset
    );

    // Draw the triangle! (3 indices starting at 0 -> 1 triangle)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}
