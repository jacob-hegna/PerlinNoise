#include <iostream>
#include <cstdlib>
#include <time.h>


#include "perlin.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int w = 512;
    int h = 512;
    PerlinNoise data(w, h, 4);

    PerlinNoise::output(data.getData(), "heightmap");
}