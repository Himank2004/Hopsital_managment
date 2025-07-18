#pragma once
#include "Person.h"

class Patient : public Person {
private:
    int patientId;
    std::string condition;

public:
    Patient(std::string name, int age, std::string gender, int id, std::string condition);

    void displayInfo() const override;

    // Specific getters
    int getPatientId() const;
    std::string getCondition() const;
};