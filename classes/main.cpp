#include <iostream>
#include <iomanip>
#include "classes.cpp"

int main()
{
    employee Arda("1000024530");

    Arda.setStartingTime(myTime(8, 58, 0), 1);
    Arda.setStartingTime(myTime(9, 01, 0), 2);
    Arda.setStartingTime(myTime(12, 0, 0), 3);
    Arda.setStartingTime(myTime(8, 30, 0), 4);
    Arda.setStartingTime(myTime(9, 15, 0), 5);

    std::cout << "=========================Mountly Report========================="
              << "\n"
              << std::setw(10) << "Day" << std::setw(10) << "Starting Time" << std::setw(10) << "Exit time"
              << "\n";
    for (int i = 0; i < 30; i++)
    {
        myTime startingTime = Arda.getStartingTime(i + 1);
        myTime exitTime = Arda.getExitTime(i + 1);
        std::cout << std::setw(10) << i + 1 << std::setw(10)
                  << startingTime.hour << "-" << startingTime.minute << "-" << startingTime.second
                  << std::setw(10)
                  << exitTime.hour << "-" << exitTime.minute << "-" << exitTime.second
                  << "\n";
    }

    std::cout << Arda.ID;

    return 0;
}