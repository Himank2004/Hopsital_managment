#pragma once
#include "Person.h"
using namespace std;

class Patient : public Person {
private:
    int patientId;
    string condition;

public:
    Patient(string name, int age, string gender, int id, string condition);

    void displayInfo() const override;

    // Specific getters
    int getPatientId() const;
    string getCondition() const;
};
