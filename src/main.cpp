#include <iostream>
#include <cstdlib>
#include <time.h>


#include "perlin.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    int w = 2048;
    int h = 2048;
    PerlinNoise data(w, h, 10);

    PerlinNoise::output(data.getData(), "heightmap");
}