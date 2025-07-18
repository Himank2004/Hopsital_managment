#pragma once
#include <string>
#include <memory>
#include "Patient.h"
#include "Doctor.h"

class Appointment {
public:
    std::string date;
    std::string time;
    std::shared_ptr<Patient> patient;
    std::shared_ptr<Doctor> doctor;

    Appointment(const std::string& date, const std::string& time, std::shared_ptr<Patient> p, std::shared_ptr<Doctor> d)
        : date(date), time(time), patient(p), doctor(d) {}

    void display() const {
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << time << std::endl;
        std::cout << "Patient: " << patient->getName() << " (ID: " << patient->getPatientId() << ")" << std::endl;
        std::cout << "Doctor: " << doctor->getName() << " (ID: " << doctor->getDoctorId() << ")" << std::endl;
    }
};