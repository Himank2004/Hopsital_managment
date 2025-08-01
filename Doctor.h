#pragma once
#include "Person.h"
#include <vector>
#include <memory> // For shared_ptr
using namespace std;


// Forward declaration to avoid circular dependency
class Patient;

class Doctor : public Person {
private:
    int doctorId;
    string specialization;
    // A doctor can be assigned to multiple patients over time, so we track one.
    // Using a weak_ptr would be even better if a patient could have multiple doctors.
    shared_ptr<Patient> assignedPatient;

public:
    Doctor(string name, int age, string gender, int id, string specialization);

    void displayInfo() const override;
    
    void assignPatient(shared_ptr<Patient> patient);
    bool isAvailable() const;
    void displayAssignedPatientInfo() const;

    // Specific getters
    int getDoctorId() const;
    string getSpecialization() const;
};
