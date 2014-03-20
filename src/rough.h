#ifndef _ROUGH_H_
#define _ROUGH_H_

#include <vector>
#include <cstdlib>

class RoughData {
public:
    RoughData(void);
    RoughData(int w, int h);
    ~RoughData(void);

    static float randomFloat(float a, float b);

    void init(int w, int h);
    float at(int x, int y);

    std::vector<std::vector<float>> getData(void);

private:
    std::vector<std::vector<float>> _data;
};

#endif