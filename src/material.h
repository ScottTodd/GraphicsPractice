#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include <GL/glew.h>

#include "camera.h"

class Material
{
public:
    Material();
    Material(std::string vertex_shader_filename,
             std::string fragment_shader_filename);

    void SetMesh(std::vector<float> vertices, std::vector<int> indices);

    void Render(Camera camera);
    void Cleanup();

private:
    std::vector<float> vertices_;
    std::vector<int> indices_;

    GLuint program_id_;
    GLuint vertex_array_id_;
    GLuint vertex_buffer_;
    GLuint element_buffer_;

    GLuint shader_model_id_;
    GLuint shader_view_id_;
    GLuint shader_projection_id_;
};

#endif // MATERIAL_H
