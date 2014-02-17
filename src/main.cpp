#include <iostream>
#include <cstdlib>
#include <time.h>

#include <png++/png.hpp>

#include "rough.h"
#include "smooth.h"
#include "perlin.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int w = 600;
    int h = 600;
    PerlinNoise data(w, h, 24);
    png::image<png::rgb_pixel> image(w, h);

    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) {
            image[i][j] = png::rgb_pixel(data.at(i, j)*255, 0, 0);
        }
    }

    image.write("image.png");
}