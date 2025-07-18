#include "Patient.h"

Patient::Patient(std::string name, int age, std::string gender, int id, std::string condition)
    : Person(name, age, gender), patientId(id), condition(condition) {}

void Patient::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Patient ID: " << patientId << std::endl;
    std::cout << "Condition: " << condition << std::endl;
}

int Patient::getPatientId() const {
    return patientId;
}

std::string Patient::getCondition() const {
    return condition;
}