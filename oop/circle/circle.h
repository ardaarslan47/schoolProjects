#include <cfloat>
#include <cmath>

const float PI = 3.14;

class Circle
{
private:
    float radius;

public:
    Circle(float radius) : radius(radius) {}

    float area()
    {
        return pow(radius, 2) * PI;
    }

    float circumference()
    {
        return radius * 2 * PI;
    }
};