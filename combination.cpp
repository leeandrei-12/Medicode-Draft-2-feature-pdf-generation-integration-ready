#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "combination.h"
#include "patientdata.h"

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (!medicodebanner())
    {
        exitprogram();
        return 0;
    }

    if (!patientconsent())
    {
        cout << "Consent was not provided. MEDICODE will now close." << endl;
        exitprogram();
        return 0;
    }

    PatientData patient{};
    SymptomData symptoms{};

    mainmenu(patient, symptoms);

    exitprogram();
    return 0;
}
