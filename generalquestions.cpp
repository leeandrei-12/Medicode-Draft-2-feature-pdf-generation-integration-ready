#include <iostream>
#include <string>
#include <limits>
#include "generalquestions.h"
#include "healthcarefacility.h"

using namespace std;

namespace
{
int getChoice(int minimum, int maximum)
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";

        if (cin >> choice && choice >= minimum && choice <= maximum)
        {
            return choice;
        }

        if (cin.eof())
        {
            return minimum;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please choose from "
             << minimum << " to " << maximum << "." << endl;
    }
}

void displaySymptomSummary(const SymptomData &symptomData)
{
    cout << endl;
    cout << "========================================" << endl;
    cout << "             SYMPTOM SUMMARY" << endl;
    cout << "========================================" << endl;
    cout << "Duration: " << symptomData.duration << endl;
    cout << "Severity: " << symptomData.severity << endl;
    cout << "Impact on Activities: " << symptomData.impact << endl;
    cout << "Progression: " << symptomData.progression << endl;
    cout << "Other Symptoms: " << symptomData.symptoms << endl;
    cout << "Urgent Signs: " << symptomData.warningSigns << endl;
    cout << "Medication/Treatment: " << symptomData.medications << endl;
    cout << "========================================" << endl;

    if (symptomData.warningSigns != "None of These" &&
        symptomData.warningSigns != "Back to Previous Question")
    {
        cout << endl;
        cout << "IMPORTANT: You selected an urgent warning sign." << endl;
        cout << "Seek immediate professional medical assistance." << endl;
        cout << "Do not wait for an automated consultation." << endl;
    }
}
}

bool generalquestions(SymptomData &symptomData)
{
    int answers[7] = {};

    const string durations[] =
    {
        "",
        "Today",
        "A Few Days",
        "One Week or Longer",
        "Not Sure"
    };

    const string severities[] =
    {
        "",
        "Mild",
        "Moderate",
        "Severe"
    };

    const string impacts[] =
    {
        "",
        "Not at All",
        "Slightly",
        "Moderately",
        "Not Sure"
    };

    const string progressions[] =
    {
        "",
        "Yes - Becoming more severe",
        "No - Staying the same",
        "Improving - Getting better",
        "Not Sure"
    };

    const string symptomChoices[] =
    {
        "",
        "Yes",
        "No",
        "Back to Previous Question",
        "Back to Main Menu"
    };

    const string warningSigns[] =
    {
        "",
        "Difficulty breathing",
        "Chest pain or pressure",
        "Fainting or sudden confusion",
        "Severe allergic reaction",
        "Feeling unsafe or needing immediate mental health support",
        "None of These",
        "Back to Previous Question"
    };

    const string medications[] =
    {
        "",
        "Yes",
        "No",
        "Not Applicable",
        "Back to Previous Question",
        "Back to Main Menu"
    };

    cout << endl;
    cout << "How long have you experienced this problem?" << endl;
    cout << "1. Today - Started today" << endl;
    cout << "2. A Few Days - Lasted 1-3 days." << endl;
    cout << "3. One Week or Longer - Lasted at least 7 days." << endl;
    cout << "4. Not Sure" << endl;
    answers[0] = getChoice(1, 4);

    cout << endl;
    cout << "How severe is your concern?" << endl;
    cout << "1. Mild - Does not greatly affect daily activities." << endl;
    cout << "2. Moderate - Makes some daily activities difficult." << endl;
    cout << "3. Severe - Makes normal daily activities very difficult." << endl;
    answers[1] = getChoice(1, 3);

    cout << endl;
    cout << "How does this concern affect activities?" << endl;
    cout << "1. Not at All - Daily activities are mostly unaffected." << endl;
    cout << "2. Slightly - Some activities are affected." << endl;
    cout << "3. Moderately - Several activities are difficult." << endl;
    cout << "4. Not Sure" << endl;
    answers[2] = getChoice(1, 4);

    cout << endl;
    cout << "Is your condition getting worse?" << endl;
    cout << "1. Yes - Becoming more severe." << endl;
    cout << "2. No - Staying the same." << endl;
    cout << "3. Improving - Getting better." << endl;
    cout << "4. Not Sure" << endl;
    answers[3] = getChoice(1, 4);

    cout << endl;
    cout << "Do you have other symptoms or concerns?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Back to Previous Question" << endl;
    cout << "4. Back to Main Menu" << endl;
    answers[4] = getChoice(1, 4);

    cout << endl;
    cout << "Are you experiencing any urgent warning signs?" << endl;
    cout << "1. Difficulty breathing" << endl;
    cout << "2. Chest pain or pressure" << endl;
    cout << "3. Fainting or sudden confusion" << endl;
    cout << "4. Severe allergic reaction" << endl;
    cout << "5. Feeling unsafe or needing immediate mental health support" << endl;
    cout << "6. None of These" << endl;
    cout << "7. Back to Previous Question" << endl;
    answers[5] = getChoice(1, 7);

    cout << endl;
    cout << "Have you taken any medication or received any treatment for this concern?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "3. Not Applicable" << endl;
    cout << "4. Back to Previous Question" << endl;
    cout << "5. Back to Main Menu" << endl;
    answers[6] = getChoice(1, 5);

    symptomData.duration = durations[answers[0]];
    symptomData.severity = severities[answers[1]];
    symptomData.impact = impacts[answers[2]];
    symptomData.progression = progressions[answers[3]];
    symptomData.symptoms = symptomChoices[answers[4]];
    symptomData.warningSigns = warningSigns[answers[5]];
    symptomData.medications = medications[answers[6]];

    symptomData.concernSummary =
        "Duration: " + symptomData.duration +
        "\nSeverity: " + symptomData.severity +
        "\nImpact on Activities: " + symptomData.impact +
        "\nProgression: " + symptomData.progression +
        "\nOther Symptoms: " + symptomData.symptoms +
        "\nUrgent Signs: " + symptomData.warningSigns +
        "\nMedication/Treatment: " + symptomData.medications;
    symptomData.summaryCompleted = true;

    cout << endl;
    cout << "========================================" << endl;
    cout << "             NEXT OPTIONS" << endl;
    cout << "========================================" << endl;
    cout << "1. View Symptom Summary" << endl;
    cout << "2. Connect to an Available General Practitioner" << endl;
    cout << "3. View General Health Guidance" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "5. Exit" << endl;

    switch (getChoice(1, 5))
    {
        case 1:
            displaySymptomSummary(symptomData);
            return false;

        case 2:
            cout << endl;
            cout << "Connecting to an Available General Practitioner..." << endl;
            healthcarefacility();
            return false;

        case 3:
            cout << endl;
            cout << "Accessing General Health Guidance..." << endl;
            cout << "Health guidance feature is not yet implemented." << endl;
            return false;

        case 4:
            cout << endl;
            cout << "Returning to Main Menu..." << endl;
            return false;

        case 5:
            cout << endl;
            cout << "Exiting MEDICODE..." << endl;
            return true;

        default:
            return false;
    }
}
