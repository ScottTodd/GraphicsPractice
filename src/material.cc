#include "material.h"

#include <iostream>

#include <common/shader.hpp>

Material::Material() {

}

Material::Material(std::string vertex_shader_filename,
                   std::string fragment_shader_filename) {
    program_id_ = LoadShaders(vertex_shader_filename.c_str(),
                             fragment_shader_filename.c_str());

    s_model_      = glGetUniformLocation(program_id_, "model");
    s_view_       = glGetUniformLocation(program_id_, "view");
    s_projection_ = glGetUniformLocation(program_id_, "projection");

    s_texture_ = glGetUniformLocation(program_id_, "texture_albedo");

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

    if (mesh.normals.size() > 0) {
        glGenBuffers(1, &b_normal_);
        glBindBuffer(GL_ARRAY_BUFFER, b_normal_);
        glBufferData(GL_ARRAY_BUFFER, mesh.normals.size() * sizeof(float),
                     &mesh.normals[0], GL_STATIC_DRAW);
    }

    if (mesh.uvs.size() > 0) {
        glGenBuffers(1, &b_uvs_);
        glBindBuffer(GL_ARRAY_BUFFER, b_uvs_);
        glBufferData(GL_ARRAY_BUFFER, mesh.uvs.size() * sizeof(float),
                     &mesh.uvs[0], GL_STATIC_DRAW);
    }

    if (mesh.indices.size() > 0) {
        glGenBuffers(1, &b_indices_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b_indices_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() *
                     sizeof(unsigned int),
                     &mesh.indices[0], GL_STATIC_DRAW);
    }
}

void Material::SetTexture(Texture &texture) {
    texture_ = texture;

    glGenTextures(1, &texture_id_);
    glBindTexture(GL_TEXTURE_2D, texture_id_);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 texture.GetWidth(), texture.GetHeight(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, &texture.GetImage()[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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

    // Bind textures.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id_);
    glUniform1i(s_texture_, 0);

    // Set vertex attributes.
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, b_vertex_);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    if (b_normal_) {
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, b_normal_);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }

    if (b_uvs_) {
        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, b_uvs_);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }

    if (mesh_.indices.size() > 0) {
        glDrawElements(GL_TRIANGLES, (int)mesh_.indices.size(),
                       GL_UNSIGNED_INT, (void*)0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, (int)mesh_.vertices.size() / 3);
    }

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

void Material::Cleanup() {
    glDeleteBuffers(1, &b_vertex_);
    glDeleteBuffers(1, &b_normal_);
    glDeleteBuffers(1, &b_indices_);
    glDeleteBuffers(1, &b_uvs_);

    glDeleteTextures(1, &texture_id_);
    glDeleteVertexArrays(1, &vertex_array_id_);
    glDeleteProgram(program_id_);
}
