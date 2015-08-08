#include "texture.h"

#include <iostream>

#include <lodepng.h>

Texture::Texture() {

}

void Texture::Load(const std::string& filename) {
    unsigned error = lodepng::decode(image, width, height, filename);

    if(error) {
        std::cout << "decoder error " << error << ": "
                  << lodepng_error_text(error) << std::endl;
    } else {
        std::cout << "Loaded image from " << filename
                  << ", width: " << width
                  << ", height: " << height << std::endl;
    }
}
