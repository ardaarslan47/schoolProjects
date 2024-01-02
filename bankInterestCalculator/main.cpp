#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include <cstring>

using namespace std;

#define RED_TEXT "\033[1;31m"
#define RESET_COLOR "\033[0m"

int main()
{
    ifstream read_file;
    cout << "Bank interest calculator! This app calculates your debit interest." << endl;
    
    const float max_interest_rate = 0.35;
    const float min_interest_rate = 0.15;
    
    float debt = 0.0, paid = 0.0, remaining_debt = 0.0, interest = 0.0, total_debt = 0.0;
    string label;
    
    cout << fixed << showpoint << setprecision(2);
    
    read_file.open("bank.txt");
    read_file >> label >> debt >> label >> paid;
    
    remaining_debt = debt - paid;
    
    if (remaining_debt > 0.0) {
        if (paid / debt < 0.20) {
            interest = remaining_debt * max_interest_rate;
            cout << "The interest rate is 0.35 because the minimum payment for the debt has not been made." << endl;
        } else {
            interest = remaining_debt * min_interest_rate;
            cout << "The interest rate is 0.15 because the minimum payment for the debt has been made." << endl;
        }
    }
    
    total_debt = interest + remaining_debt;
    
    cout << "Original Debt:" << setw(10) << RED_TEXT << "$" << debt << RESET_COLOR << endl;
    cout << "Paid Amount:" << setw(10) << RED_TEXT << "$" << paid << RESET_COLOR << endl;
    cout << "Remaining Debt:" << setw(10) << RED_TEXT << "$" << remaining_debt << RESET_COLOR << endl;
    cout << "Interest:" << setw(10) << RED_TEXT << "$" << interest << RESET_COLOR << endl;
    cout << "Total Debt:" << setw(10) << RED_TEXT << "$" << total_debt << RESET_COLOR << endl;
    
    
    return 0;
}
