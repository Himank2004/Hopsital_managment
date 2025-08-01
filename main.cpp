#include <iostream>
#include "HospitalFacade.h"
using namespace std;

void showMenu() {
     cout << "\n\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n";
     cout << "\t1. Register Patient\n";
     cout << "\t2. Register Doctor\n";
     cout << "\t3. Schedule Appointment\n";
     cout << "\t4. View Patients Database\n";
     cout << "\t5. View Doctors Database\n";
     cout << "\t6. View All Appointments\n";
     cout << "\t7. Exit\n";
     cout << "\n\tEnter your choice: ";
}

int main() {
    HospitalFacade facade;
    int choice;

    while (true) {
        showMenu();
         cin >> choice;
         cin.ignore(); // Consume the newline character

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
                 cout << "\n\t!! Exiting the system. Thank you! !!\n";
                return 0;
            default:
                 cout << "\n\tInvalid choice! Please try again.\n";
                break;
        }
         cout << "\n\tPress Enter to continue...";
         cin.get();
    }

    return 0;
}
