#pragma once
#include <vector>
#include <memory>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
using namespace std;

// Singleton Class for managing the entire hospital system
class Hospital {
private:
    vector<shared_ptr<Patient>> patients;
    vector<shared_ptr<Doctor>> doctors;
    vector<shared_ptr<Appointment>> appointments;

    // Private constructor to prevent instantiation
    Hospital() {}

public:
    // Delete copy constructor and assignment operator
    Hospital(const Hospital&) = delete;
    Hospital& operator=(const Hospital&) = delete;

    // Static method to get the single instance of the class
    static Hospital& getInstance() {
        static Hospital instance; // Lazily instantiated on first use
        return instance;
    }
    
    void addPatient(shared_ptr<Patient> p);
    void addDoctor(shared_ptr<Doctor> d);
    
    shared_ptr<Patient> findPatientById(int id);
    shared_ptr<Doctor> findDoctorById(int id);
    shared_ptr<Doctor> findAvailableDoctor(const string& specialization);
    
    void createAppointment(const string& date, const string& time, shared_ptr<Patient> p, shared_ptr<Doctor> d);

    void displayAllPatients() const;
    void displayAllDoctors() const;
    void displayAllAppointments() const;
};
