#include <string>

class Person {
private:
    std::string name;
    unsigned short age;
    std::string country;
    unsigned short index;

public:
    Person(std::string name, unsigned short age, std::string country, unsigned short index)
        : name(name), age(age), country(country), index(index) {}
    ~Person() {}

    std::string getName() const { return name; }
    unsigned short getAge() const { return age; }
    std::string getCountry() const { return country; }
    unsigned short getIndex() const { return index; }

    void setName(const std::string& nName) { name = nName; }
    void setAge(unsigned short nAge) { age = nAge; }
    void setCountry(const std::string& nCountry) { country = nCountry; }
};