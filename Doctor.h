#pragma once
#include "Person.h"
#include <vector>
#include <memory> // For std::shared_ptr

// Forward declaration to avoid circular dependency
class Patient;

class Doctor : public Person {
private:
    int doctorId;
    std::string specialization;
    // A doctor can be assigned to multiple patients over time, so we track one.
    // Using a weak_ptr would be even better if a patient could have multiple doctors.
    std::shared_ptr<Patient> assignedPatient;

public:
    Doctor(std::string name, int age, std::string gender, int id, std::string specialization);

    void displayInfo() const override;
    
    void assignPatient(std::shared_ptr<Patient> patient);
    bool isAvailable() const;
    void displayAssignedPatientInfo() const;

    // Specific getters
    int getDoctorId() const;
    std::string getSpecialization() const;
};