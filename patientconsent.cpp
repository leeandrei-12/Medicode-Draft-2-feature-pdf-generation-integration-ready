#include <iostream>
#include "patientconsent.h"

using namespace std;

bool patientconsent()
{
    int choice;

    cout << endl;
    cout << "===============================================================" << endl;
    cout << "                      PATIENT CONSENT" << endl;
    cout << "===============================================================" << endl;
    cout << endl;
    cout << "By using MEDICODE, your personal and medical information will be" << endl;
    cout << "collected to help provide healthcare navigation" << endl;
    cout << "and connect you with a GP." << endl << endl;

    cout << "1. Agree" << endl;
    cout << "2. Disagree" << endl;
    cout << "Enter your choice: ";

    if (!(cin >> choice))
    {
        return false;
    }

    if (choice == 1)
    {
        cout << "Consent recorded." << endl;
        return true;
    }

    if (choice == 2)
    {
        return false;
    }

    cout << "Invalid choice. Consent was not recorded." << endl;
    return false;
}
