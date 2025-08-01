#include "Patient.h"
using namespace std;

Patient::Patient( string name, int age,  string gender, int id,  string condition)
    : Person(name, age, gender), patientId(id), condition(condition) {}

void Patient::displayInfo() const {
     cout << "Name: " << name <<  endl;
     cout << "Age: " << age <<  endl;
     cout << "Gender: " << gender <<  endl;
     cout << "Patient ID: " << patientId <<  endl;
     cout << "Condition: " << condition <<  endl;
}

int Patient::getPatientId() const {
    return patientId;
}

 string Patient::getCondition() const {
    return condition;
}
