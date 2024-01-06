#include <string>

class GradeCalculator
{
public:
    float read_grade(int& midterm, int& quiz, int& endterm);
    std::string calculate_letter_grade(float& grade);
};
