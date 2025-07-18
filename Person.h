#pragma once
#include <iostream>
#include <string>

// Abstract base class using the concept of an "Interface"
class Person {
protected:
    std::string name;
    int age;
    std::string gender;

public:
    Person(std::string name, int age, std::string gender)
        : name(name), age(age), gender(gender) {}

    virtual ~Person() {} // Virtual destructor for proper cleanup

    // Pure virtual function to be implemented by derived classes
    virtual void displayInfo() const = 0;

    // Common getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
};