#include <iostream>
#include "rectangle.h"

void mainMenu(float &length, float &width);
int main()
{
    float length = -1, width = -1;
    mainMenu(length, width);

    while (length < 0 || width < 0)
    {
        std::cout << "Please enter valid values" << std::endl
                  << std::endl;
        mainMenu(length, width);
    }

    Rectangle rectangle = Rectangle(length, width);

    std::cout << "Area: " << rectangle.area() << std::endl
              << "Perimeter: " << rectangle.perimeter();

    return 0;
}

void mainMenu(float &length, float &width)
{
    std::cout << "Rectangle area and perimeter calculator!"
              << std::endl
              << std::endl
              << "Length: ";
    std::cin >> length;
    std::cout << "Width: ";
    std::cin >> width;
}