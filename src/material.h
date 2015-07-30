#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include <GL/glew.h>

#include "camera.h"
#include "light.h"
#include "mesh.h"

class Material {
public:
    Material();
    Material(std::string vertex_shader_filename,
             std::string fragment_shader_filename);

    void SetMesh(Mesh mesh);

    void Render(Camera camera, Light light);
    void Cleanup();

private:
    Mesh mesh_;

    GLuint program_id_;
    GLuint vertex_array_id_;
    GLuint vertex_buffer_;
    GLuint indices_buffer_;

    GLuint s_model_;
    GLuint s_view_;
    GLuint s_projection_;

    GLuint s_light_position_;
    GLuint s_light_color_;
};

#endif // MATERIAL_H
