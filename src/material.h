#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

#include <GL/glew.h>

#include "camera.h"

class Material
{
public:
    Material();
    Material(std::string vertex_shader_filename,
             std::string fragment_shader_filename);

    void Render(Camera camera);
    void Cleanup();

private:
    GLuint program_id;
    GLuint matrix_id;
    GLuint vertexbuffer;
    GLuint vertex_array_id;
};

#endif // MATERIAL_H
