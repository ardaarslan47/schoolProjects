#include <iostream>
#include "printStars.cpp"

using namespace std;

int main()
{
    int rows = -1, counter, spaces;
    
    while (rows < 0 || rows > 30) {
        cout << "Please enter number of row (1-30): ";
        cin >> rows;
    }
    
    cout << endl << endl;
    spaces = 30;
    
    StarPrinter c;
    for (counter = 1; counter <= rows ; counter++) 
    {
        c.printStar(spaces, counter);
        spaces--;
    }
    
    cout << endl << endl;
    return 0;
}
