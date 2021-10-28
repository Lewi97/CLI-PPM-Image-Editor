#include <iostream>

#include "Parser.h"
#include "PPM.h"

void handleCommand(const CommandData& data, PPM& img)
{
    switch (data.ID)
    {
    case CommandID::Pixel:      img.drawPixel(data.x, data.y, data.rgb); break;
    case CommandID::Rectangle:  img.drawRectangle(data.x,data.y,data.width,data.height,data.rgb); break;
    case CommandID::Circle:     img.drawCircle(data.x, data.y, data.radius, data.rgb); break;
    case CommandID::Save:       img.finalize(data.filename.c_str()); break;
    }
}

int main()
{
    std::string commands = "Commands:\n"
        "new                        = create new image\n"
        "save      filename         = save image with filename\n"
        "circle    x y radius r g b = draw circle at x y with radius and 0-255 rgb\n"
        "rectangle x y w h r g b    = draw rectangle at x y with width and height and 0-255 rgb\n"
        "pixel     x y r g b        = draw pixel with 0-255 rgb at x y\n"
        ;

    std::cout << commands << std::endl;

    PPM image(100,100);
    Parser p;
    std::string command;

    while (command != "exit")
    {
        std::getline(std::cin, command);
        CommandData data = p.Parse(command);
        handleCommand(data, image);
    }

    return 0;
}
