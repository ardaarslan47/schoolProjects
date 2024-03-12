#include <cfloat>

class Rectangle
{
private:
    float length;
    float width;

public:
    Rectangle(float length, float width) : length(length), width(width) {}

    float area()
    {
        return length * width;
    }

    float perimeter()
    {
        return 2 * (length + width);
    }
};