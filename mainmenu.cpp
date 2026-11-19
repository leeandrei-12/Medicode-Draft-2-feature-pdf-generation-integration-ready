#include <iostream>
#include <limits>
#include "mainmenu.h"
#include "generalquestions.h"
#include "patientpersonalinfo.h"
#include "pdfgenerator.h"

using namespace std;

namespace
{
int getMainMenuChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";

        if (cin >> choice)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        if (cin.eof())
        {
            return 4;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
    }
}
}

void mainmenu(PatientData &patient, SymptomData &symptoms)
{
    bool running = true;

    while (running)
    {
        cout << endl;
        cout << "===============================================================" << endl;
        cout << "                          MAIN MENU" << endl;
        cout << "===============================================================" << endl;

        cout << "1. REQUEST A DOCTOR" << endl;
        cout << "2. PATIENT PROFILE" << endl;
        cout << "3. PRINT PATIENT SUMMARY" << endl;
        cout << "4. EXIT" << endl;

        switch (getMainMenuChoice())
        {
            case 1:
                if (generalquestions(symptoms))
                {
                    running = false;
                }
                break;

            case 2:
                patientpersonalinfo(patient);
                break;

            case 3:
                if (!patient.profileCompleted && !symptoms.summaryCompleted)
                {
                    cout << "No patient information or symptom summary is available yet." << endl;
                    cout << "Complete a patient profile or symptom questionnaire first." << endl;
                }
                else
                {
                    generatePatientPDF(patient, symptoms);
                }
                break;

            case 4:
                running = false;
                break;

            default:
                cout << "Please choose a valid option from 1 to 4." << endl;
                break;
        }
    }
}
