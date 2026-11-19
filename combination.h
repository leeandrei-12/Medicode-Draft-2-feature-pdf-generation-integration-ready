#pragma once

#include "patientdata.h"

bool medicodebanner();
bool patientconsent();
void mainmenu(PatientData &patient, SymptomData &symptoms);
void patientpersonalinfo(PatientData &patient);
bool generalquestions(SymptomData &symptomData);
void healthcarefacility();
void exitprogram();
