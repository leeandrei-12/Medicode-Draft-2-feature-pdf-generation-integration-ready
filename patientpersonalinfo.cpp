#include <iostream>
#include <limits>
#include <random>
#include <set>
#include <string>
#include "patientdata.h"
#include "patientpersonalinfo.h"

using namespace std;


// STORES GENERATED PATIENT IDs
set<string> usedPatientIDs;


// GENERATES A UNIQUE RANDOM PATIENT ID
string generatePatientID()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dist(100000, 999999);

    string patientID;

    do
    {
        patientID = "MED-" + to_string(dist(gen));
    }
    while (usedPatientIDs.find(patientID) != usedPatientIDs.end());

    usedPatientIDs.insert(patientID);

    return patientID;
}


// PATIENT PERSONAL INFORMATION
void patientpersonalinfo(PatientData &patient)
{
    int sexChoice;
    int option;

    // Start a fresh profile when the user opens the patient profile again.
    patient = PatientData{};

    // GENERATE PATIENT ID
    patient.patientID = generatePatientID();



    cout << endl;
    cout << "=============================================" << endl;
    cout << "           PATIENT'S INFORMATION" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "USER ID AND INFORMATION" << endl;
    cout << "Patient ID: " << patient.patientID << endl;


    // I. GENERAL DATA
    cout << endl;
    cout << "I. GENERAL DATA" << endl;

cout << "Name of Patient: ";
getline(cin, patient.name);
    cout << "Age: ";
    getline(cin, patient.age);

    cout << endl;
    cout << "Sex:" << endl;
    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Enter choice: ";
    cin >> sexChoice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (sexChoice == 1)
    {
        patient.sex = "Male";
    }
    else if (sexChoice == 2)
    {
        patient.sex = "Female";
    }
    else
    {
        patient.sex = "Not Specified";
    }

    cout << "Address: ";
    getline(cin, patient.address);

    cout << "Civil Status: ";
    getline(cin, patient.civilStatus);


    // II. HISTORY OF PRESENT ILLNESS

    cout << endl;
    cout << "II. HISTORY OF PRESENT ILLNESS" << endl;

    cout << "History of Present Illness: ";
    getline(cin, patient.historyPresentIllness);


    // III. PAST MEDICAL HISTORY
    cout << endl;
    cout << "III. PAST MEDICAL HISTORY" << endl;


    cout << endl;
    cout << "OPERATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.operations = "Yes";
    else if (option == 2)
        patient.operations = "No";
    else
        patient.operations = "Unknown";


    cout << endl;
    cout << "IMMUNIZATIONS:" << endl;
    cout << "1. Complete" << endl;
    cout << "2. Incomplete" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.immunizations = "Complete";
    else if (option == 2)
        patient.immunizations = "Incomplete";
    else
        patient.immunizations = "Unknown";


    cout << endl;
    cout << "ALLERGIES:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.allergies = "Yes";
    else if (option == 2)
        patient.allergies = "No";
    else
        patient.allergies = "Unknown";


    cout << endl;
    cout << "HOSPITALIZATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.hospitalizations = "Yes";
    else if (option == 2)
        patient.hospitalizations = "No";
    else
        patient.hospitalizations = "Unknown";


    cout << endl;
    cout << "MAINTENANCE MEDICATIONS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.maintenanceMeds = "Yes";
    else if (option == 2)
        patient.maintenanceMeds = "No";
    else
        patient.maintenanceMeds = "Unknown";


    cout << endl;
    cout << "OTHERS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.othersMedical = "Yes";
    else
        patient.othersMedical = "No";


    // IV. FAMILY HISTORY
    cout << endl;
    cout << "IV. FAMILY HISTORY" << endl;


    cout << endl;
    cout << "BRONCHIAL ASTHMA:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.bronchialAsthma = "Yes";
    else if (option == 2)
        patient.bronchialAsthma = "No";
    else
        patient.bronchialAsthma = "Unknown";


    cout << endl;
    cout << "DIABETES MELLITUS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.diabetesMellitus = "Yes";
    else if (option == 2)
        patient.diabetesMellitus = "No";
    else
        patient.diabetesMellitus = "Unknown";


    cout << endl;
    cout << "HYPERTENSION:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.hypertension = "Yes";
    else if (option == 2)
        patient.hypertension = "No";
    else
        patient.hypertension = "Unknown";


    cout << endl;
    cout << "PULMONARY TUBERCULOSIS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.pulmonaryTuberculosis = "Yes";
    else if (option == 2)
        patient.pulmonaryTuberculosis = "No";
    else
       patient.pulmonaryTuberculosis = "Unknown";


    cout << endl;
    cout << "OTHERS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.othersFamily = "Yes";
    else
        patient.othersFamily = "No";


    // V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY

    cout << endl;
    cout << "V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;


    cout << endl;
    cout << "SMOKER:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Former Smoker" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.smoker = "Yes";
    else if (option == 2)
        patient.smoker = "No";
    else
        patient.smoker = "Former Smoker";


    cout << endl;
    cout << "ALCOHOLIC BEVERAGE DRINKER:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Occasionally" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.alcoholicBeverageDrinker = "Yes";
    else if (option == 2)
       patient.alcoholicBeverageDrinker = "No";
    else
        patient. alcoholicBeverageDrinker = "Occasionally";


    cout << endl;
    cout << "WORK/ENVIRONMENTAL HAZARDS:" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Unknown" << endl;
    cout << "Enter choice: ";
    cin >> option;

    if (option == 1)
        patient.workEnvironmentalHazards = "Yes";
    else if (option == 2)
        patient.workEnvironmentalHazards = "No";
    else
        patient.workEnvironmentalHazards = "Unknown";


    // VI. OB-GYNE HISTORY
    // FEMALE only

    if (sexChoice == 2)
    {
        cout << endl;
        cout << "VI. OB-GYNE HISTORY" << endl;


        cout << endl;
        cout << "MENARCHE:" << endl;
        cout << "1. Before 10 years old" << endl;
        cout << "2. 10-12 years old" << endl;
        cout << "3. 13-15 years old" << endl;
        cout << "4. 16 years old or above" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.menarche = "Before 10 years old";
        else if (option == 2)
            patient.menarche = "10-12 years old";
        else if (option == 3)
            patient.menarche = "13-15 years old";
        else if (option == 4)
            patient.menarche = "16 years old or above";
        else
            patient.menarche = "Unknown";


        cout << endl;
        cout << "MENSTRUAL HISTORY:" << endl;
        cout << "1. Regular" << endl;
        cout << "2. Irregular" << endl;
        cout << "3. Not Applicable" << endl;
        cout << "4. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.menstrualHistory = "Regular";
        else if (option == 2)
            patient.menstrualHistory = "Irregular";
        else if (option == 3)
            patient.menstrualHistory = "Not Applicable";
        else
            patient.menstrualHistory = "Unknown";


        cout << endl;
        cout << "GRAVIDA:" << endl;
        cout << "1. 0" << endl;
        cout << "2. 1" << endl;
        cout << "3. 2" << endl;
        cout << "4. 3 or more" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.gravida = "0";
        else if (option == 2)
            patient.gravida = "1";
        else if (option == 3)
            patient.gravida = "2";
        else if (option == 4)
            patient.gravida = "3 or more";
        else
            patient.gravida = "Unknown";


        cout << endl;
        cout << "PARA:" << endl;
        cout << "1. No living children" << endl;
        cout << "2. One living child" << endl;
        cout << "3. Two living children" << endl;
        cout << "4. Three or more living children" << endl;
        cout << "5. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.para = "No living children";
        else if (option == 2)
            patient.para = "One living child";
        else if (option == 3)
            patient.para = "Two living children";
        else if (option == 4)
            patient.para = "Three or more living children";
        else
            patient.para = "Unknown";


        cout << endl;
        cout << "LAST MENSTRUAL PERIOD:" << endl;
        cout << "1. Within the last month" << endl;
        cout << "2. 1-3 months ago" << endl;
        cout << "3. More than 3 months ago" << endl;
        cout << "4. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.lastMenstrualPeriod = "Within the last month";
        else if (option == 2)
            patient.lastMenstrualPeriod = "1-3 months ago";
        else if (option == 3)
            patient.lastMenstrualPeriod = "More than 3 months ago";
        else
            patient.lastMenstrualPeriod = "Unknown";


        cout << endl;
        cout << "MENOPAUSE:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "3. Unknown" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.menopause = "Yes";
        else if (option == 2)
            patient.menopause = "No";
        else
            patient.menopause = "Unknown";


        cout << endl;
        cout << "OTHERS:" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
            patient.othersOBGyne = "Yes";
        else
            patient.othersOBGyne = "No";
    }


    // PATIENT SUMMARY
    cout << endl;
    cout << "=============================================" << endl;
    cout << "          PATIENT INFORMATION SUMMARY" << endl;
    cout << "=============================================" << endl;

    cout << endl;
    cout << "Patient ID: " << patient.patientID << endl;

    cout << endl;
    cout << "I. GENERAL DATA" << endl;
    cout << "Name: " << patient.name << endl;
    cout << "Age: " << patient.age << endl;
    cout << "Sex: " << patient.sex << endl;
    cout << "Address: " << patient.address << endl;
    cout << "Civil Status: " << patient.civilStatus << endl;


    cout << endl;
    cout << "II. HISTORY OF PRESENT ILLNESS" << endl;
    cout << patient.historyPresentIllness << endl;


    cout << endl;
    cout << "III. PAST MEDICAL HISTORY" << endl;
    cout << "Operations: " << patient.operations << endl;
    cout << "Immunizations: " << patient.immunizations << endl;
    cout << "Allergies: " << patient.allergies << endl;
    cout << "Hospitalizations: " << patient.hospitalizations << endl;
    cout << "Maintenance Medications: " << patient.maintenanceMeds << endl;
    cout << "Others: " << patient.othersMedical << endl;


    cout << endl;
    cout << "IV. FAMILY HISTORY" << endl;
    cout << "Bronchial Asthma: " << patient.bronchialAsthma << endl;
    cout << "Diabetes Mellitus: " <<patient.diabetesMellitus << endl;
    cout << "Hypertension: " << patient.hypertension << endl;
    cout << "Pulmonary Tuberculosis: " << patient.pulmonaryTuberculosis << endl;
    cout << "Others: " << patient.othersFamily << endl;


    cout << endl;
    cout << "V. SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY" << endl;
    cout << "Smoker: " << patient.smoker << endl;
    cout << "Alcoholic Beverage Drinker: "
         << patient.alcoholicBeverageDrinker << endl;
    cout << "Work/Environmental Hazards: "
         << patient.workEnvironmentalHazards << endl;


    // SHOW OB-GYNE SUMMARY ONLY FOR FEMALE
    if (sexChoice == 2)
    {
        cout << endl;
        cout << "VI. OB-GYNE HISTORY" << endl;
        cout << "Menarche: " << patient.menarche << endl;
        cout << "Menstrual History: " << patient.menstrualHistory << endl;
        cout << "Gravida: " << patient.gravida << endl;
        cout << "Para: " <<patient.para << endl;
        cout << "Last Menstrual Period: "
             << patient.lastMenstrualPeriod << endl;
        cout << "Menopause: " << patient.menopause << endl;
        cout << "Others: " << patient.othersOBGyne << endl;
    }



    patient.profileCompleted = true;
    cout << endl;
    cout << "Returning to Main Menu..." << endl;
}
