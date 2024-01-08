#include <iostream>
#include <cstring>
using namespace std;

void printNumsBetween(int first, int second, int numbers_total, string type){
    type[0] = toupper(type[0]);
    cout << type << " numbers between:" << endl;
    type[0] = tolower(type[0]);
    for (int i = first; i < second; i = i + 2) {
        cout << i << " ";
        numbers_total = numbers_total + i;
    }
    cout << endl << "Total of " << type << " numbers between: " << numbers_total << endl << endl;
}

int main() {
    int firstNumber = 0, secondNumber = 0;
    int numbers_total = 0;
    
    while (firstNumber >= secondNumber) {
        cout << "Enter two numbers. (first one must be lower than second)" << endl;
        cin >> firstNumber >> secondNumber;
    }
    cout << endl << endl;
    
    if (firstNumber % 2 == 0) {
        printNumsBetween(firstNumber+1, secondNumber, numbers_total, "odd");
        printNumsBetween(firstNumber+2, secondNumber, numbers_total, "even");
    } else {
        printNumsBetween(firstNumber+2, secondNumber, numbers_total, "odd");
        printNumsBetween(firstNumber+1, secondNumber, numbers_total, "even");
    }
    
    return 0;
}
