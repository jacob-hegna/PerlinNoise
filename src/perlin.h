#ifndef _PERLIN_H_
#define _PERLIN_H_

#include <vector>
#include <string>
#include <iostream>

#include <png++/png.hpp>

#include "smooth.h"

class PerlinNoise {
public:
    PerlinNoise(void);
    PerlinNoise(int w, int h, int octaves);
    ~PerlinNoise(void);

    void init(int w, int h, int octaves);

    static void output(std::vector<std::vector<float>> data, std::string path);
    float at(int x, int y);

    std::vector<std::vector<float>> getData(void);
private:
    std::vector<std::vector<float>> _data;
};

#endif