#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

class Texture {
public:
    Texture();

    void Load(const std::string& filename);

private:
    std::vector<unsigned char> image;
    unsigned width;
    unsigned height;
};

#endif // TEXTURE_H
