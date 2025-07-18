#include "Doctor.h"
#include "Patient.h" // Include full definition here

Doctor::Doctor(std::string name, int age, std::string gender, int id, std::string specialization)
    : Person(name, age, gender), doctorId(id), specialization(specialization), assignedPatient(nullptr) {}

void Doctor::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Doctor ID: " << doctorId << std::endl;
    std::cout << "Specialization: " << specialization << std::endl;
}

void Doctor::assignPatient(std::shared_ptr<Patient> patient) {
    assignedPatient = patient;
}

bool Doctor::isAvailable() const {
    // A doctor is available if they have no assigned patient.
    return assignedPatient == nullptr;
}

void Doctor::displayAssignedPatientInfo() const {
    if (isAvailable()) {
        std::cout << "Doctor is available." << std::endl;
    } else {
        std::cout << "Assigned Patient: " << assignedPatient->getName() << std::endl;
    }
}

int Doctor::getDoctorId() const {
    return doctorId;
}

std::string Doctor::getSpecialization() const {
    return specialization;
}