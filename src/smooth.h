#ifndef _SMOOTH_H_
#define _SMOOTH_H_

#define M_PI 3.14159265358979323846

#include <iostream>

#include "rough.h"

class SmoothNoise {
public: 
    SmoothNoise(void);
    SmoothNoise(int w, int h, int octave);
    ~SmoothNoise(void);

    static float interpolate(float x0, float x1, float alpha);

    void init(int w, int h, int octave);

    float at(int x, int y);

    std::vector<std::vector<float>> getData(void);

private:
    std::vector<std::vector<float>> _data;
};

#endif