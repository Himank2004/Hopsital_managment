#include "HospitalFacade.h"
#include "Hospital.h"
#include <iostream>
#include <memory> // for std::make_shared

void HospitalFacade::registerPatient() {
    std::string name, gender, condition;
    int age, id;
    std::cout << "\tEnter patient name: ";
    std::getline(std::cin, name);
    std::cout << "\tEnter age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "\tEnter gender: ";
    std::getline(std::cin, gender);
    std::cout << "\tEnter patient ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "\tEnter patient's condition: ";
    std::getline(std::cin, condition);

    auto patient = std::make_shared<Patient>(name, age, gender, id, condition);
    Hospital::getInstance().addPatient(patient);
    std::cout << "\n\t!! PATIENT ADDED SUCCESSFULLY !!\n";
}

void HospitalFacade::registerDoctor() {
    std::string name, gender, specialization;
    int age, id;
    std::cout << "\tEnter doctor name: ";
    std::getline(std::cin, name);
    std::cout << "\tEnter age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "\tEnter gender: ";
    std::getline(std::cin, gender);
    std::cout << "\tEnter doctor ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "\tEnter specialization: ";
    std::getline(std::cin, specialization);
    
    auto doctor = std::make_shared<Doctor>(name, age, gender, id, specialization);
    Hospital::getInstance().addDoctor(doctor);
    std::cout << "\n\t!! DOCTOR ADDED SUCCESSFULLY !!\n";
}

void HospitalFacade::scheduleAppointment() {
    std::cout << "\tEnter Patient ID for appointment: ";
    int patientId;
    std::cin >> patientId;
    std::cin.ignore();

    auto patient = Hospital::getInstance().findPatientById(patientId);
    if (!patient) {
        std::cout << "\tPatient not found!\n";
        return;
    }

    std::cout << "\tEnter required doctor specialization (matches patient condition): ";
    std::string specialization;
    std::getline(std::cin, specialization);

    auto doctor = Hospital::getInstance().findAvailableDoctor(specialization);
    if (!doctor) {
        std::cout << "\tNo available doctor with that specialization found.\n";
        return;
    }

    std::string date, time;
    std::cout << "\tEnter appointment date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "\tEnter appointment time (HH:MM): ";
    std::getline(std::cin, time);

    Hospital::getInstance().createAppointment(date, time, patient, doctor);
}

void HospitalFacade::viewAllPatients() {
    Hospital::getInstance().displayAllPatients();
}

void HospitalFacade::viewAllDoctors() {
    Hospital::getInstance().displayAllDoctors();
}

void HospitalFacade::viewAllAppointments() {
    Hospital::getInstance().displayAllAppointments();
}