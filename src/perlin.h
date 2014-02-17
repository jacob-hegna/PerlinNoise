#ifndef _PERLIN_H_
#define _PERLIN_H_

#include <vector>

#include "smooth.h"

class PerlinNoise {
public:
    PerlinNoise(void);
    PerlinNoise(int w, int h, int octaves);
    ~PerlinNoise(void);

    void init(int w, int h, int octaves);

    float at(int x, int y);

    std::vector<std::vector<float>> getData(void);
private:
    std::vector<std::vector<float>> _data;
};

#endif