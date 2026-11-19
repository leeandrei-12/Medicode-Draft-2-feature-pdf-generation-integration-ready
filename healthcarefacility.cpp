#include <iostream>
#include "healthcarefacility.h"
#include <string>

using namespace std;

void healthcarefacility()   

{
    int facilityChoice;
    int doctorChoice;
    string number;
    string location;
    string fee;
    string time;
    string day;

    cout << endl;
    cout << "\033[31m===================================\033[0m" << endl;
    cout << "\033[31m||\033[0m  CHOOSE A HEALTHCARE FACILITY \033[31m||\033[0m" << endl;
    cout << "\033[31m===================================\033[0m" << endl;

    cout << "1. Public Hospital" << endl;
    cout << "2. Private Hospital" << endl;
    cout << "3. Back to Main Menu" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> facilityChoice;


    // PUBLIC 

    if (facilityChoice == 1)
    {
        cout << endl;
        cout << "AVAILABLE PUBLIC DOCTORS" << endl;

        cout << "1. Dr. Adrian Villanueva" << endl;
        cout << "2. Dr. Marcus Javier" << endl;
        cout << "3. Dr. Nathaniel Cruz" << endl;

        cout << "Select Doctor: ";
        cin >> doctorChoice;

        switch (doctorChoice)
        {
            case 1:

                number = "09178362451                                  \033[31m||\033[0m";
                location = "West Visayas State University Medical Center \033[31m||\033[0m";
                fee = "300-800 PHP                                  \033[31m||\033[0m";
                day = "Monday, Wednesday, Friday                    \033[31m||\033[0m";
                time = "8:00 AM - 11:00 AM and 1:00 PM - 4:00 PM     \033[31m||\033[0m";
                

                break;

            case 2:

                number = "09285619374                                  \033[31m||\033[0m";
                location = "Metro Iloilo Hospital and MedicalCenter, Inc.\033[31m||\033[0m";
                fee = "600-1000 PHP                                 \033[31m||\033[0m";
                day = "Tuesday, Thursday, Saturday                  \033[31m||\033[0m";
                time = "9:00 AM - 12:00 PM and 2:00 PM - 5:00 PM     \033[31m||\033[0m";

                break;

            case 3:

                number = "09285619374                                  \033[31m||\033[0m";
                location = "Western Visayas Medical Center               \033[31m||\033[0m";
                fee = "500-1000 PHP                                 \033[31m||\033[0m";
                day = "Wednesday, Friday, Sunday                    \033[31m||\033[0m";
                time = "8:00 AM - 11:00 AM and 2:00 PM - 4:00 PM     \033[31m||\033[0m";

                break;

            default:

                cout << "Invalid doctor selection!" << endl;

                return;
        }
    }


    // PRIVATE 

    else if (facilityChoice == 2)
    {
        cout << endl;
        cout << "AVAILABLE PRIVATE DOCTORS" << endl;

        cout << "1. Dr. Daniel Santiago" << endl;
        cout << "2. Dr. Matthew Alcantara" << endl;
        cout << "3. Dr. Gabriel Mendoza" << endl;

        cout << "Select Doctor: ";
        cin >> doctorChoice;

        switch (doctorChoice)
        {
            case 1:

                number = "09162483957                                  \033[31m||\033[0m";
                location = "Iloilo Doctor's Hospital                     \033[31m||\033[0m";
                fee = "800-1800 PHP                                 \033[31m||\033[0m";
                day = "Monday, Tuesday, Saturday                    \033[31m||\033[0m";
                time = "9:00 AM - 12:00 AM and 3:00 PM - 5:00 PM     \033[31m||\033[0m";

                number = "09162483957                              \033[31m||\033[0m";
                location = "Iloilo Mission HospitalL                  \033[31m||\033[0m";
                fee = "1000 PHP                                 \033[31m||\033[0m";
                day = "Monday, Tuesday, Saturday                \033[31m||\033[0m";
                time = "9:00 AM - 12:00 AM and 3:00 PM - 5:00 PM \033[31m||\033[0m";

                break;

            case 2:

                number = "09273461825                                  \033[31m||\033[0m";
                location = "The Medical City Iloilo                      \033[31m||\033[0m";
                fee = "1000 - 2000 PHP                              \033[31m||\033[0m";
                day = "Wednesday, Friday, Saturday                  \033[31m||\033[0m";
                time = "8:00 AM - 11:00 AM and 1:00 PM - 4:00 PM     \033[31m||\033[0m";

                break;

            case 3:

                number = "09986732145                                  \033[31m||\033[0m";
                location = "St. Paul's Hospital Iloilo                   \033[31m||\033[0m";
                fee = "1000-2000 PHP                                \033[31m||\033[0m";
                day = "Tuesday, Thursday, Saturday                  \033[31m||\033[0m";
                time = "9:00 AM - 12:00 AM and 1:00 PM - 3:00 PM     \033[31m||\033[0m";

                break;

            default:

                cout << "Invalid doctor selection!" << endl;

                return;
        }
    }


    // BACK TO MAIN MENU

    else if (facilityChoice == 3)
    {
        cout << endl;
        cout << "Returning to Main Menu..." << endl;

    }


    // EXIT

    else if (facilityChoice == 4)
    {
        cout << endl;

        cout << "Exiting the program..." << endl;
    }


    // INVALID FACILITY

    else
    {
        cout << "Invalid selection!" << endl;

        return;
    }


    // SELECTED DOCTOR

    cout << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << "\033[31m||\033[0m                           Selected Doctor!                               \033[31m||\033[0m" << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << "\033[31m||\033[0m Doctor's Contact Number: |  " << number << endl;
    cout << "\033[31m||\033[0m Doctor's Location:       |  " << location << endl;
    cout << "\033[31m||\033[0m Consultation Fee:        |  " << fee << endl;
    cout << "\033[31m||\033[0m Days of Availability:    |  " << day << endl;
    cout << "\033[31m||\033[0m Time of Availability:    |  " << time << endl;
    cout << "\033[31m==============================================================================\033[0m" << endl;
    cout << endl;
    cout << "Dialing the Doctor..." << endl;
    cout << endl;
}
