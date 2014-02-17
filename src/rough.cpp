#include "rough.h"

RoughData::RoughData(void) {

}

RoughData::RoughData(int w, int h) {
    init(w, h);
}

RoughData::~RoughData(void) {
    for(int i = 0; i < _data.size(); ++i) {
        _data.at(i).clear();
    }
    _data.clear();
}

// static function
float RoughData::randomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void RoughData::init(int w, int h) {
    for(int i = 0; i < w; ++i) {
        std::vector<float> temp;
        _data.push_back(temp);

        for(int j = 0; j < h; ++j) {
            _data.at(i).push_back(randomFloat(0.f, 1.f));
        
        }
    }
}

float RoughData::at(int x, int y) {
    return _data.at(x).at(y);
}

std::vector<std::vector<float>> RoughData::getData(void) {
    return _data;
}