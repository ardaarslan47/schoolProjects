#include <iostream>
#include <vector>
#include <string>
#include "person.h"

std::vector<Person> people;

void updatePerson(Person &person)
{
    std::string name, country;
    unsigned short age;

    std::cin.ignore();
    std::cout << "\nEnter new name: ";
    std::getline(std::cin, name);

    std::cout << "Enter new age: ";
    std::cin >> age;

    std::cin.ignore();
    std::cout << "Enter new country: ";
    std::getline(std::cin, country);

    person.setName(name);
    person.setAge(age);
    person.setCountry(country);

    std::cout << "Person details updated successfully.\n";
}

void deletePerson(unsigned short index)
{
    people.erase(people.begin() + index - 1);
    std::cout << "Person deleted successfully.\n";
}

void displayPerson(const Person &person)
{
    std::cout << "\nDetails of " << person.getName() << ":\n";
    std::cout << "Name: " << person.getName() << "\n";
    std::cout << "Age: " << person.getAge() << "\n";
    std::cout << "Country: " << person.getCountry() << "\n";

    int choice;
    std::cout << "\n1- Update\n"
              << "2- Delete\n"
              << "0- Back\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        updatePerson(people[person.getIndex()]);
        break;

    case 2:
        deletePerson(person.getIndex());
        break;

    case 0:
        break;

    default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
}

void displayPeople()
{
    if (people.empty())
    {
        std::cout << "\nThere are no people to display. Please add a new person.\n";
        return;
    }

    std::cout << "\nPeople List:\n";
    for (size_t i = 0; i < people.size(); ++i)
    {
        std::cout << i + 1 << "- " << people[i].getName() << "\n";
    }

    unsigned short choice;
    std::cout << "\nEnter the number to display details or 0 to go back: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= people.size())
    {
        displayPerson(people[choice - 1]);
    }
}

void createPerson()
{
    std::string name, country;
    unsigned short age;

    std::cin.ignore();
    std::cout << "\nEnter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter age: ";
    std::cin >> age;
    if (age <= 0)
    {
        std::cerr << "Invalid age entered. Please enter a valid age.\n";
        return;
    }

    std::cin.ignore();
    std::cout << "Enter country: ";
    std::getline(std::cin, country);

    people.emplace_back(name, age, country, people.size());
    std::cout << "Person added successfully.\n";
}
