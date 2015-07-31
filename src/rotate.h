#ifndef ROTATE_H
#define ROTATE_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "component.h"

class Rotate : public Component {
public:
    Rotate();

    ~Rotate() {}

    void Update(float delta_time);
    void Render() const {}
    void Cleanup();

private:
    float x_;
    float y_;
    float z_;
};

#endif // ROTATE_H
