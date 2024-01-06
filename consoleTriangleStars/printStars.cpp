#include "printStars.h"
#include <iostream>

void StarPrinter::printStar(int spaces, int stars)
{
    int i;
    for (i = 1; i <= spaces; i++) {
        std::cout << " ";
    }
    for (i = 1; i <= stars; i++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}
