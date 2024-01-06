#include "gradecalculator.h"
#include <string>

void GradeCalculator::calculate_grade(int midterm, int quiz, int endterm, float& grade)
{
    grade = (0.30 * midterm) + (0.10 * quiz) + (0.60 * endterm);
}

std::string GradeCalculator::calculate_letter_grade(float grade)
{
    std::string letters[7] = {"AA", "BA", "BB", "CB", "CC", "DC", "DD"};
    int grades[7] =          {85,    75,   70,   65,   60,   55,   50};

    for (int i = 0; i < 7; i++) {
        if (grade >= grades[i]) {
            return letters[i];
        }
    }
    
    return "FF";
}
