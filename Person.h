#pragma once
#include <iostream>
#include <string>
using namespace std;

// Abstract base class using the concept of an "Interface"
class Person {
protected:
     string name;
    int age;
     string gender;

public:
    Person( string name, int age,  string gender)
        : name(name), age(age), gender(gender) {}

    virtual ~Person() {} // Virtual destructor for proper cleanup

    // Pure virtual function to be implemented by derived classes
    virtual void displayInfo() const = 0;

    // Common getters
     string getName() const { return name; }
    int getAge() const { return age; }
     string getGender() const { return gender; }
};
