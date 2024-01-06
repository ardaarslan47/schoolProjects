#include "gradecalculator.cpp"
#include <iostream>
#include <cfloat>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int midterm, quiz, endterm;
    
    cout << "Please enter midterm, quiz and endterm grades in order." << endl;
    cin >> midterm >> quiz >> endterm;
    
    GradeCalculator c;
    float grade = c.read_grade(midterm, quiz, endterm);
    cout << fixed << setprecision(2)
         << "Grade: " << setw(10)
         << grade << endl;
    
    cout << "Letter Grade: " << setw(10) << c.calculate_letter_grade(grade) << endl;
    return 0;
}
