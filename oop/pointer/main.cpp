#include <vector>
#include <string>
#include <iostream>

class User
{

public:
    std::string name;
    User(std::string n) : name(n){};
    User(){};
    ~User(){};
};

int main()
{
    // example 1

    // creating new pointers that points to user named Arda and Azize
    User *a = new User("Arda");
    User *b = new User("Azize");

    // i want to store these in array so creating user pointer array
    User *users[2] = {};

    users[0] = a; // 0x6000 not exactly but something like this
    users[1] = b; // same

    std::cout <<
        //-> arrow gets value from pointer
        users[0]->name

              << "\n"
              << users[1]->name;

    delete a;
    delete b;

    // example 1.5
    int *x = new int(4);
    int *y = new int(5);

    std::cout << "\n"
              // adress of a pointer
              << &x
              << "\n"
              // pointer
              << x
              << "\n"
              // value
              << *x
              << "\n";

    delete x;
    delete y;

    // example 2
    std::vector<User> userVector;

    // creating pointers
    User *m = new User("Umut");
    User *n = new User("Ozan");

    // m and n are pointer but vector is user vector.
    // when using * without type name referes to what variable points to
    // so User *m is user pointer and *m is what m is pointing to
    userVector.push_back(*m);
    userVector.push_back(*n);

    std::cout << userVector[0].name << "\n" << userVector[1].name << "\n";

    delete m;
    delete n;

    // example 2.5
    std::vector<User*> userPointerVector;

    // like example 1 if you want to use pointer array, list, vector etc.
    // you can create objects and use & to push adress of these objects
    User u = User("A"), o = User("B");
    userPointerVector.push_back(&u);
    userPointerVector.push_back(&o);

    // when you use this aproach like example 1 use -> to get value from adress
    std:: cout << userPointerVector[0]->name << "\n" << userPointerVector[1]->name << "\n";

    // example 3

    // integer t is st to 4
    int t = 4;
    std::cout << t << "\n";
    // integer pointer pT is set to adress of t
    int* pT = &t;
    std::cout << pT << "\n";
    // (integer pointer) pointer ppt is set to adress of pT
    int** ppT = &pT;
    std::cout << ppT << "\n";
    // ((integer pointer) pointer) pointer pppt is set to adress of ppT
    int*** pppT = &ppT;
    std::cout << pppT << "\n";

    return 0;
}