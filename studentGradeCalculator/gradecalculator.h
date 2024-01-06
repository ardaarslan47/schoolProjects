#include <string>

class GradeCalculator
{
public:
    void calculate_grade(int midterm, int quiz, int endterm, float& grade);
    std::string calculate_letter_grade(float grade);
};
