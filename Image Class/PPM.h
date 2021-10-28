#pragma once

#include <fstream>

struct RGB {
    int r;
    int g;
    int b;
};
// (TODO) fix boundary check
class PPM
{
private:
    int width, height;
    RGB* colors = nullptr;

    inline size_t getIndex(int x, int y) { return x + width * y; }
    inline bool inBounds(int x, int y);
    void drawPixel(size_t index, RGB c) { colors[index] = c; }
public:
    PPM(int width, int height);
    ~PPM() { delete[] colors; }

    void drawRectangle(int x, int y, int w, int h, RGB c);
    void drawCircle(int x, int y, int r, RGB c);
    void fill(RGB c);
    void drawPixel(int x, int y, RGB c) { colors[getIndex(x, y)] = c; }

    void finalize(const char* fileName);
};