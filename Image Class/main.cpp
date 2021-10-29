#include <iostream>

#include "Parser.h"
#include "PPM.h"

int main()
{
    std::string commands = "Commands:\n"
        "new       w h          = create new image with width and height\n"
        "save      filename     = save image with filename\n"
        "circle    x y radius   = draw circle at x y with radius\n"
        "rectangle x y w h      = draw rectangle at x y with width and height\n"
        "pixel     x y          = draw pixel at x y\n"
        "color     r g b        = set drawing colors with r g b\n"
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
