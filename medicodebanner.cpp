#include <iostream>
#include <string>
#include "medicodebanner.h"

using namespace std;

bool medicodebanner()
{
    string code;
    int choice;

    cout << "Input USSD: ";
    if (!(cin >> code))
    {
        return false;
    }

    if (code != "*206#")
    {
        cout << "USSD Invalid. Please Try Again." << endl;
        return false;
    }

    cout << "\033[1;38;5;88m";
    cout << R"(

███╗   ███╗███████╗██████╗ ██╗ ██████╗ ██████╗ ██████╗ ███████╗
████╗ ████║██╔════╝██╔══██╗██║██╔════╝██╔═══██╗██╔══██╗██╔════╝
██╔████╔██║█████╗  ██║  ██║██║██║     ██║   ██║██║  ██║█████╗
██║╚██╔╝██║██╔══╝  ██║  ██║██║██║     ██║   ██║██║  ██║██╔══╝
██║ ╚═╝ ██║███████╗██████╔╝██║╚██████╗╚██████╔╝██████╔╝███████╗
╚═╝     ╚═╝╚══════╝╚═════╝ ╚═╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
)" << endl;
    cout << "\033[0m";

    cout << "        A USSD Code for Non-critical Medical Assistance." << endl;
    cout << "                  MEDICODE USSD CODE: *206#" << endl << endl;
    cout << "===============================================================" << endl;
    cout << "                        DISCLAIMER:" << endl;
    cout << "===============================================================" << endl;
    cout << endl;
    cout << "MEDICODE asks questions about your symptoms and" << endl;
    cout << "connects you to available General Practitioners (GPs)" << endl;
    cout << "who can provide general health guidance." << endl << endl;
    cout << "It caters only to Green Triage cases, which are" << endl;
    cout << "generally non-emergency conditions that are bearable" << endl;
    cout << "and can wait for routine medical assessment." << endl << endl;
    cout << "A GP may refer you to a Specialized Practitioner" << endl;
    cout << "if necessary." << endl << endl;
    cout << "MEDICODE does not directly diagnose illnesses or" << endl;
    cout << "provide Specialized Practitioner consultations." << endl;
    cout << "===============================================================" << endl << endl;

    cout << "1. Proceed" << endl;
    cout << "2. No" << endl;
    cout << "Enter your choice: ";

    if (!(cin >> choice))
    {
        return false;
    }

    if (choice == 1)
    {
        cout << "Proceeding to Patient Consent Form..." << endl;
        return true;
    }

    cout << "MEDICODE was not started." << endl;
    return false;
}
