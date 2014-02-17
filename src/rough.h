#ifndef _ROUGH_H_
#define _ROUGH_H_

#include <vector>

class RoughData {
public:
    RoughData(void) {

    }
    RoughData(int w, int h) {
        init(w, h);
    }
    ~RoughData(void) {
        for(int i = 0; i < _data.size(); ++i) {
            _data.at(i).clear();
        }
        _data.clear();
    }

    static float randomFloat(float a, float b) {
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = b - a;
        float r = random * diff;
        return a + r;
    }

    void init(int w, int h) {
        for(int i = 0; i < w; ++i) {
            std::vector<float> temp;
            _data.push_back(temp);

            for(int j = 0; j < h; ++j) {
                _data.at(i).push_back(randomFloat(0.f, 1.f));
            
            }
        }
    }

    float at(int x, int y) {
        return _data.at(x).at(y);
    }

    std::vector<std::vector<float>> getData(void) {
        return _data;
    }

private:
    std::vector<std::vector<float>> _data;
};

#endif