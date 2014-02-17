#include "perlin.h"

PerlinNoise::PerlinNoise(void) {

}

PerlinNoise::PerlinNoise(int w, int h, int octaves) {
    init(w, h, octaves);
}

PerlinNoise::~PerlinNoise(void) {

}

void PerlinNoise::init(int w, int h, int octaves) {
    for(int i = 0; i < w; ++i) {
        std::vector<float> temp;
        _data.push_back(temp);
        for(int j = 0; j < h; ++j) {
            _data.at(i).push_back(0);
        }
    }

    std::vector<std::vector<std::vector<float>>> smoothData;
    for(int i = 0; i < octaves; ++i) {
        SmoothNoise smooth(w, h, i);
        smoothData.push_back(smooth.getData());
    }

    float persistance = 0.5f;
    float amplitude = 1.0f;
    float totalAmplitude = 0.0f;

    for(int o = octaves - 1; o >= 0; --o) {
        amplitude *= persistance;
        totalAmplitude += amplitude;
        for(int i = 0; i < w; ++i) {
            for(int j = 0; j < h; ++j) {
                _data.at(i).at(j) += smoothData.at(o).at(i).at(j) * amplitude;
            }
        }
        output(smoothData.at(o), "test" + std::to_string(o));
    }

    for(int i = 0; i < w; ++i) {
        for(int j = 0; j < h; ++j) {
            _data.at(i).at(j) /= totalAmplitude;
        }
    }

    for(int o = 0; o < octaves; ++o) {
        for(int i = 0; i < w; ++i) {
            smoothData.at(o).at(i).clear();
        }
        smoothData.at(o).clear();
    }
    smoothData.clear();
}

void PerlinNoise::output(std::vector<std::vector<float>> data, std::string path) {
    int w = data.size();
    int h = data.at(0).size();
    std::ofstream file(path + ".csv");
    png::image<png::rgb_pixel> image(w, h);

    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            float tempValue = data.at(i).at(j);
            char tempColor = tempValue * 255;
            image[i][j] = png::rgb_pixel(tempColor, tempColor, tempColor);

            file << tempValue;
            if (j != h) file << ", ";
        }
        file << std::endl;
    }

    image.write(path + ".png");
    file.close();
}


float PerlinNoise::at(int x, int y) {
    return _data.at(x).at(y);
}

std::vector<std::vector<float>> PerlinNoise::getData(void) {
    return _data;
}