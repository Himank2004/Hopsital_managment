#include "Hospital.h"

void Hospital::addPatient(std::shared_ptr<Patient> p) {
    patients.push_back(p);
}

void Hospital::addDoctor(std::shared_ptr<Doctor> d) {
    doctors.push_back(d);
}

std::shared_ptr<Patient> Hospital::findPatientById(int id) {
    for (const auto& p : patients) {
        if (p->getPatientId() == id) {
            return p;
        }
    }
    return nullptr;
}

std::shared_ptr<Doctor> Hospital::findDoctorById(int id) {
    for (const auto& d : doctors) {
        if (d->getDoctorId() == id) {
            return d;
        }
    }
    return nullptr;
}

std::shared_ptr<Doctor> Hospital::findAvailableDoctor(const std::string& specialization) {
    for (const auto& d : doctors) {
        if (d->getSpecialization() == specialization && d->isAvailable()) {
            return d;
        }
    }
    return nullptr;
}

void Hospital::createAppointment(const std::string& date, const std::string& time, std::shared_ptr<Patient> p, std::shared_ptr<Doctor> d) {
    d->assignPatient(p);
    auto appointment = std::make_shared<Appointment>(date, time, p, d);
    appointments.push_back(appointment);
    std::cout << "\n\t!! APPOINTMENT SCHEDULED SUCCESSFULLY !!\n";
}

void Hospital::displayAllPatients() const {
    std::cout << "\n\t--- LIST OF PATIENTS ---\n";
    for (const auto& p : patients) {
        p->displayInfo();
        std::cout << "-----------------------\n";
    }
}

void Hospital::displayAllDoctors() const {
    std::cout << "\n\t--- LIST OF DOCTORS ---\n";
    for (const auto& d : doctors) {
        d->displayInfo();
        std::cout << "-----------------------\n";
    }
}

void Hospital::displayAllAppointments() const {
    std::cout << "\n\t--- LIST OF APPOINTMENTS ---\n";
    for (const auto& a : appointments) {
        a->display();
        std::cout << "-----------------------\n";
    }
}
