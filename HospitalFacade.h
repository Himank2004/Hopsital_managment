#pragma once
#include <string>

// Facade to simplify interactions with the hospital system
class HospitalFacade {
public:
    void registerPatient();
    void registerDoctor();
    void scheduleAppointment();
    void viewAllPatients();
    void viewAllDoctors();
    void viewAllAppointments();
};