#include "smooth.h"

SmoothNoise::SmoothNoise(void) {

}
SmoothNoise::SmoothNoise(int w, int h, int octave) {
    init(w, h, octave);
}
SmoothNoise::~SmoothNoise(void) {
    for(int i = 0; i < _data.size(); ++i) {
        _data.at(i).clear();
    }
    _data.clear();
}

// static function
float SmoothNoise::interpolate(float x0, float x1, float alpha) {
    double mu2 = (1-cos(alpha*M_PI))/2;
    return(x0*(1-alpha)+x0*mu2);
    //return (x0 * (1 - alpha) + alpha * x1);
}

void SmoothNoise::init(int w, int h, int octave) {
    RoughData rough(w, h);

    int period    = 1 << octave;
    int frequency = 1.f / (float)period;

    for(int i = 0; i < w; ++i) {
        std::vector<float> temp;
        _data.push_back(temp);

        int i0 = (i / period) * period;
        int i1 = (i0 + period) % w;
        float horizontalBlend = (i - i0) * frequency;

        for(int j = 0; j < h; ++j) {
            int j0 = (j / period) * period;
            int j1 = (j0 + period) % h;

            float verticalBlend = (j - j0) * frequency;

            float top = interpolate(rough.at(i0, j0),
                                    rough.at(i1, j0),
                                    horizontalBlend);

            float bottom = interpolate(rough.at(i0, j1),
                                       rough.at(i1, j1),
                                       horizontalBlend);

            _data.at(i).push_back(interpolate(top, bottom, verticalBlend));
        }
    }
}

float SmoothNoise::at(int x, int y) {
    return _data.at(x).at(y);
}

std::vector<std::vector<float>> SmoothNoise::getData(void) {
    return _data;
}