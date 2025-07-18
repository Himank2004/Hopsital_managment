#include <iostream>
#include "HospitalFacade.h"

void showMenu() {
    std::cout << "\n\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n";
    std::cout << "\t1. Register Patient\n";
    std::cout << "\t2. Register Doctor\n";
    std::cout << "\t3. Schedule Appointment\n";
    std::cout << "\t4. View Patients Database\n";
    std::cout << "\t5. View Doctors Database\n";
    std::cout << "\t6. View All Appointments\n";
    std::cout << "\t7. Exit\n";
    std::cout << "\n\tEnter your choice: ";
}

int main() {
    HospitalFacade facade;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1:
                facade.registerPatient();
                break;
            case 2:
                facade.registerDoctor();
                break;
            case 3:
                facade.scheduleAppointment();
                break;
            case 4:
                facade.viewAllPatients();
                break;
            case 5:
                facade.viewAllDoctors();
                break;
            case 6:
                facade.viewAllAppointments();
                break;
            case 7:
                std::cout << "\n\t!! Exiting the system. Thank you! !!\n";
                return 0;
            default:
                std::cout << "\n\tInvalid choice! Please try again.\n";
                break;
        }
        std::cout << "\n\tPress Enter to continue...";
        std::cin.get();
    }

    return 0;
}