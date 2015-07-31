#ifndef ROTATE_H
#define ROTATE_H

#include <glm/glm.hpp>

#include "component.h"

class Rotate : public Component {
public:
    Rotate();
    Rotate(glm::vec3 axis_speeds);
    Rotate(float x, float y, float z);

    ~Rotate() {}

    void Update(float delta_time);
    void Render() const {}
    void Cleanup();

    glm::vec3 axis_speeds;
};

#endif // ROTATE_H
