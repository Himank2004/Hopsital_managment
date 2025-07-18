#pragma once
#include <vector>
#include <memory>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"

// Singleton Class for managing the entire hospital system
class Hospital {
private:
    std::vector<std::shared_ptr<Patient>> patients;
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::vector<std::shared_ptr<Appointment>> appointments;

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
    
    void addPatient(std::shared_ptr<Patient> p);
    void addDoctor(std::shared_ptr<Doctor> d);
    
    std::shared_ptr<Patient> findPatientById(int id);
    std::shared_ptr<Doctor> findDoctorById(int id);
    std::shared_ptr<Doctor> findAvailableDoctor(const std::string& specialization);
    
    void createAppointment(const std::string& date, const std::string& time, std::shared_ptr<Patient> p, std::shared_ptr<Doctor> d);

    void displayAllPatients() const;
    void displayAllDoctors() const;
    void displayAllAppointments() const;
};