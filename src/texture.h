#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

class Texture {
public:
    Texture();

    void Load(const std::string& filename);

    unsigned int GetWidth() const { return width; }
    unsigned int GetHeight() const { return height; }
    const std::vector<unsigned char>& GetImage() { return image; }

private:
    std::vector<unsigned char> image;
    unsigned int width;
    unsigned int height;
};

#endif // TEXTURE_H
