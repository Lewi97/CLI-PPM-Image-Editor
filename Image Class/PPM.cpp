#include "PPM.h"

#include <iostream>

PPM::PPM(int width, int height) : 
    width(width), height(height), colors(new RGB[width * height])
{
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            colors[x + width * y] = { 255,255,255 };

    std::cout << colors << std::endl;
    // std::cout << colors[123].r << std::endl;
}

inline bool PPM::inBounds(int x, int y)
{
    if (0 < x && x < width)
        return (0 < y && y < height);
    return false;
}

void PPM::drawRectangle(int x, int y, int w, int h, RGB c)
{
    for (int x0 = 0; x0 < w; x0++)
        for (int y0 = 0; y0 < h; y0++)
        {
            if (!inBounds(x + x0, y + y0)) continue;
            drawPixel(x + x0, y + y0, c);
        }
}

void PPM::drawCircle(int x, int y, int r, RGB c)
{
    for (int y0 = -r; y0 <= r; y0++)
        for (int x0 = -r; x0 <= r; x0++)
            if (x0 * x0 + y0 * y0 <= r * r)
            {
                if (!inBounds(x + x0, y + y0)) continue;
                drawPixel(x + x0, y + y0, c);
            }
}

void PPM::fill(RGB c)
{
    drawRectangle(0, 0, width, height, c);
}

void PPM::finalize(const char* fileName)
{
    std::ofstream img;
    int counter = 0;

    img.open(fileName);
    img << "P3 " << width << ' ' << height;
    img << "\n255\n";
    for (int i = 0; i < width * height; i++)
    {
        RGB c = colors[i];
        img << c.r << ' ';
        img << c.g << ' ';
        img << c.b << ' ';
        if (++counter & 8)
        {
            img << '\n';
            counter ^= 8;
        }
    }
    img.close();
}
