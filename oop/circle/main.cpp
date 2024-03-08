#include <iostream>
#include "circle.h"

using namespace std;

int main() {
    float radius;

    cout << "Please enter radius for calculate area and circumference: ";
    cin >> radius;

    Circle circle = Circle(radius);

    cout << "Area: " << circle.area()
    << endl << "Circumference: "
    << circle.circumference();

    return 0;
}