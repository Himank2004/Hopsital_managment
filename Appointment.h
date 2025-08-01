#pragma once
#include <string>
#include <memory>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

class Appointment {
public:
    string date;
    string time;
    shared_ptr<Patient> patient;
    shared_ptr<Doctor> doctor;

    Appointment(const string& date, const string& time, shared_ptr<Patient> p, shared_ptr<Doctor> d)
        : date(date), time(time), patient(p), doctor(d) {}

    void display() const {
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Patient: " << patient->getName() << " (ID: " << patient->getPatientId() << ")" << endl;
        cout << "Doctor: " << doctor->getName() << " (ID: " << doctor->getDoctorId() << ")" << endl;
    }
};
