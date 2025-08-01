#include "Hospital.h"
using namespace std;

void Hospital::addPatient(shared_ptr<Patient> p) {
    patients.push_back(p);
}

void Hospital::addDoctor(shared_ptr<Doctor> d) {
    doctors.push_back(d);
}

shared_ptr<Patient> Hospital::findPatientById(int id) {
    for (const auto& p : patients) {
        if (p->getPatientId() == id) {
            return p;
        }
    }
    return nullptr;
}

shared_ptr<Doctor> Hospital::findDoctorById(int id) {
    for (const auto& d : doctors) {
        if (d->getDoctorId() == id) {
            return d;
        }
    }
    return nullptr;
}

shared_ptr<Doctor> Hospital::findAvailableDoctor(const string& specialization) {
    for (const auto& d : doctors) {
        if (d->getSpecialization() == specialization && d->isAvailable()) {
            return d;
        }
    }
    return nullptr;
}

void Hospital::createAppointment(const string& date, const string& time, shared_ptr<Patient> p, shared_ptr<Doctor> d) {
    d->assignPatient(p);
    auto appointment = make_shared<Appointment>(date, time, p, d);
    appointments.push_back(appointment);
    cout << "\n\t!! APPOINTMENT SCHEDULED SUCCESSFULLY !!\n";
}

void Hospital::displayAllPatients() const {
    cout << "\n\t--- LIST OF PATIENTS ---\n";
    for (const auto& p : patients) {
        p->displayInfo();
        cout << "-----------------------\n";
    }
}

void Hospital::displayAllDoctors() const {
    cout << "\n\t--- LIST OF DOCTORS ---\n";
    for (const auto& d : doctors) {
        d->displayInfo();
        cout << "-----------------------\n";
    }
}

void Hospital::displayAllAppointments() const {
    cout << "\n\t--- LIST OF APPOINTMENTS ---\n";
    for (const auto& a : appointments) {
        a->display();
        cout << "-----------------------\n";
    }
}
