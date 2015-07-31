#include "material.h"

#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <common/shader.hpp>

#include "camera.h"
#include "light.h"
#include "mesh.h"

Material::Material() {

}

Material::Material(std::string vertex_shader_filename,
                   std::string fragment_shader_filename) {
    program_id_ = LoadShaders(vertex_shader_filename.c_str(),
                             fragment_shader_filename.c_str());

    s_model_      = glGetUniformLocation(program_id_, "model");
    s_view_       = glGetUniformLocation(program_id_, "view");
    s_projection_ = glGetUniformLocation(program_id_, "projection");

    s_light_position_ = glGetUniformLocation(program_id_, "light.position");
    s_light_color_    = glGetUniformLocation(program_id_, "light.color");
    s_light_power_    = glGetUniformLocation(program_id_, "light.power");
}

void Material::SetMesh(Mesh &mesh) {
    mesh_ = mesh;

    // TODO: Delete buffers and vertex arrays if they already exist.

    glGenVertexArrays(1, &vertex_array_id_);
    glBindVertexArray(vertex_array_id_);

    glGenBuffers(1, &b_vertex_);
    glBindBuffer(GL_ARRAY_BUFFER, b_vertex_);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float),
                 &mesh.vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &b_normal_);
    glBindBuffer(GL_ARRAY_BUFFER, b_normal_);
    glBufferData(GL_ARRAY_BUFFER, mesh.normals.size() * sizeof(float),
                 &mesh.normals[0], GL_STATIC_DRAW);

    glGenBuffers(1, &b_indices_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b_indices_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() *
                 sizeof(unsigned int),
                 &mesh.indices[0], GL_STATIC_DRAW);
}

void Material::Render(Camera camera, Light light,
                      glm::mat4 model_transform) const {
    glUseProgram(program_id_);

    // Set updated uniforms.
    glUniformMatrix4fv(s_model_, 1, GL_FALSE, &model_transform[0][0]);
    glUniformMatrix4fv(s_view_, 1, GL_FALSE, &camera.GetView()[0][0]);
    glUniformMatrix4fv(s_projection_, 1, GL_FALSE,
                       &camera.GetProjection()[0][0]);

    glUniform3fv(s_light_position_, 1, &light.position[0]);
    glUniform3fv(s_light_color_, 1, &light.color[0]);
    glUniform1fv(s_light_power_, 1, &light.power);

    // Set vertex attributes.
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, b_vertex_);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, b_normal_);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawElements(GL_TRIANGLES, (int)mesh_.indices.size(), GL_UNSIGNED_INT,
                   (void*)0);

    glDisableVertexAttribArray(0);
}

void Material::Cleanup() {
    glDeleteBuffers(1, &b_vertex_);
    glDeleteBuffers(1, &b_normal_);
    glDeleteBuffers(1, &b_indices_);
    glDeleteVertexArrays(1, &vertex_array_id_);
    glDeleteProgram(program_id_);
}
