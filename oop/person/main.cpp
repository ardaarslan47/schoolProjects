#include <iostream>
#include "functions.cpp"

int main()
{
    int choice;
    std::cout << "Person management system\n";

    do
    {
        std::cout << "\n1- Display all people\n"
                  << "2- Create new person\n"
                  << "0- Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displayPeople();
            break;

        case 2:
            createPerson();
            break;

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}