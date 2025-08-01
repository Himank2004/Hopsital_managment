#include "HospitalFacade.h"
#include "Hospital.h"
#include <iostream>
#include <memory> // for make_shared
using namespace std;

void HospitalFacade::registerPatient() {
    string name, gender, condition;
    int age, id;
    cout << "\tEnter patient name: ";
    getline(cin, name);
    cout << "\tEnter age: ";
    cin >> age;
    cin.ignore();
    cout << "\tEnter gender: ";
    getline(cin, gender);
    cout << "\tEnter patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "\tEnter patient's condition: ";
    getline(cin, condition);

    auto patient = make_shared<Patient>(name, age, gender, id, condition);
    Hospital::getInstance().addPatient(patient);
    cout << "\n\t!! PATIENT ADDED SUCCESSFULLY !!\n";
}

void HospitalFacade::registerDoctor() {
    string name, gender, specialization;
    int age, id;
    cout << "\tEnter doctor name: ";
    getline(cin, name);
    cout << "\tEnter age: ";
    cin >> age;
    cin.ignore();
    cout << "\tEnter gender: ";
    getline(cin, gender);
    cout << "\tEnter doctor ID: ";
    cin >> id;
    cin.ignore();
    cout << "\tEnter specialization: ";
    getline(cin, specialization);
    
    auto doctor = make_shared<Doctor>(name, age, gender, id, specialization);
    Hospital::getInstance().addDoctor(doctor);
    cout << "\n\t!! DOCTOR ADDED SUCCESSFULLY !!\n";
}

void HospitalFacade::scheduleAppointment() {
    cout << "\tEnter Patient ID for appointment: ";
    int patientId;
    cin >> patientId;
    cin.ignore();

    auto patient = Hospital::getInstance().findPatientById(patientId);
    if (!patient) {
        cout << "\tPatient not found!\n";
        return;
    }

    cout << "\tEnter required doctor specialization (matches patient condition): ";
    string specialization;
    getline(cin, specialization);

    auto doctor = Hospital::getInstance().findAvailableDoctor(specialization);
    if (!doctor) {
        cout << "\tNo available doctor with that specialization found.\n";
        return;
    }

    string date, time;
    cout << "\tEnter appointment date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "\tEnter appointment time (HH:MM): ";
    getline(cin, time);

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
