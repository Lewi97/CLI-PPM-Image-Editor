#include <iostream>

#include "Parser.h"
#include "PPM.h"

int main()
{
    std::string commands = "Commands:\n"
        "new       w h              = create new image with width and height\n"
        "save      filename         = save image with filename\n"
        "circle    x y radius r g b = draw circle at x y with radius and 0-255 rgb\n"
        "rectangle x y w h r g b    = draw rectangle at x y with width and height and 0-255 rgb\n"
        "pixel     x y r g b        = draw pixel with 0-255 rgb at x y\n"
        ;

    std::cout << commands << std::endl;

    PPM* image = new PPM(100, 100);
    Parser p;
    std::string command;

    while (command != "exit")
    {
        std::getline(std::cin, command);
        p.execute(command, image);
    }

    return 0;
}
