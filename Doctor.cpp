#include "Doctor.h"
#include "Patient.h" // Include full definition here
using namespace std;

Doctor::Doctor(string name, int age, string gender, int id, string specialization)
    : Person(name, age, gender), doctorId(id), specialization(specialization), assignedPatient(nullptr) {}

void Doctor::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Doctor ID: " << doctorId << endl;
    cout << "Specialization: " << specialization << endl;
}

void Doctor::assignPatient(shared_ptr<Patient> patient) {
    assignedPatient = patient;
}

bool Doctor::isAvailable() const {
    // A doctor is available if they have no assigned patient.
    return assignedPatient == nullptr;
}

void Doctor::displayAssignedPatientInfo() const {
    if (isAvailable()) {
        cout << "Doctor is available." << endl;
    } else {
        cout << "Assigned Patient: " << assignedPatient->getName() << endl;
    }
}

int Doctor::getDoctorId() const {
    return doctorId;
}

string Doctor::getSpecialization() const {
    return specialization;
}
