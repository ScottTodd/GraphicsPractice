#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "camera.h"
#include "light.h"
#include "mesh.h"
#include "texture.h"

class Material {
public:
    Material();
    Material(std::string vertex_shader_filename,
             std::string fragment_shader_filename);

    void SetMesh(Mesh &mesh);
    void SetTexture(Texture &texture);

    void Render(Camera camera, Light light, glm::mat4 model_transform) const;
    void Cleanup();

private:
    Mesh mesh_;
    Texture texture_;

    // Miscellaneous handles.
    GLuint program_id_;
    GLuint vertex_array_id_;
    GLuint texture_id_;

    // Buffers.
    GLuint b_vertex_;
    GLuint b_normal_;
    GLuint b_indices_;
    GLuint b_uvs_;

    // Matrices.
    GLuint s_model_;
    GLuint s_view_;
    GLuint s_projection_;

    // Textures.
    GLuint s_texture_;

    // Lights.
    GLuint s_light_position_;
    GLuint s_light_color_;
    GLuint s_light_power_;
};

#endif // MATERIAL_H
