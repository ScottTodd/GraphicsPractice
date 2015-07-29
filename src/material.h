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
    GLuint program_id_;
    GLuint matrix_id_;
    GLuint vertex_array_id_;
    GLuint vertex_buffer_;
    GLuint element_buffer_;
};

#endif // MATERIAL_H
