#include "material.h"

#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <common/shader.hpp>

#include "camera.h"

Material::Material() {

}

Material::Material(std::string vertex_shader_filename,
                   std::string fragment_shader_filename) {
    program_id_ = LoadShaders(vertex_shader_filename.c_str(),
                             fragment_shader_filename.c_str());

    // Get a handle for our "MVP" uniform
    matrix_id_ = glGetUniformLocation(program_id_, "MVP");
}

void Material::SetMesh(std::vector<float> vertices, std::vector<int> indices) {
    glGenVertexArrays(1, &vertex_array_id_);
    glBindVertexArray(vertex_array_id_);

    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &element_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int),
                 &indices[0], GL_STATIC_DRAW);
}

void Material::Render(Camera camera) {
    glUseProgram(program_id_);

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    // Model matrix : identity matrix (model will be at the origin)
    glm::mat4 mvp = camera.TransformModel(glm::mat4(1.0f));
    glUniformMatrix4fv(matrix_id_, 1, GL_FALSE, &mvp[0][0]);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
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
}

void Material::Cleanup() {
    glDeleteBuffers(1, &vertex_buffer_);
    glDeleteProgram(program_id_);
    glDeleteVertexArrays(1, &vertex_array_id_);
}
