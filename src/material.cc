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

    shader_model_id_      = glGetUniformLocation(program_id_, "model");
    shader_view_id_       = glGetUniformLocation(program_id_, "view");
    shader_projection_id_ = glGetUniformLocation(program_id_, "projection");
}

void Material::SetMesh(std::vector<float> vertices, std::vector<int> indices) {
    vertices_ = vertices;
    indices_ = indices;

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

    // Send in updated uniforms.
    glUniformMatrix4fv(shader_model_id_, 1, GL_FALSE,
                       &glm::mat4(1.0f)[0][0]);
    glUniformMatrix4fv(shader_view_id_, 1, GL_FALSE,
                       &camera.GetView()[0][0]);
    glUniformMatrix4fv(shader_projection_id_, 1, GL_FALSE,
                       &camera.GetProjection()[0][0]);

    // Bind vertex attribute.
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, (int)indices_.size());

    glDisableVertexAttribArray(0);
}

void Material::Cleanup() {
    glDeleteBuffers(1, &vertex_buffer_);
    glDeleteBuffers(1, &element_buffer_);
    glDeleteVertexArrays(1, &vertex_array_id_);
    glDeleteProgram(program_id_);
}
