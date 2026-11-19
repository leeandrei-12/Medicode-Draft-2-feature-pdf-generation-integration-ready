#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "pdfgenerator.h"
#include "PDFgen/pdfgen.h"

using namespace std;

namespace
{
const double PAGE_TOP = 790.0;
const double PAGE_BOTTOM = 50.0;
const double LEFT_MARGIN = 50.0;
const size_t MAX_LINE_LENGTH = 88;

string displayValue(const string &value)
{
    return value.empty() ? "Not provided" : value;
}

vector<string> wrapText(const string &text, size_t maxLength)
{
    vector<string> lines;
    string logicalLine;
    istringstream input(text);

    while (getline(input, logicalLine))
    {
        istringstream words(logicalLine);
        string word;
        string line;

        while (words >> word)
        {
            if (line.empty())
            {
                line = word;
            }
            else if (line.length() + 1 + word.length() <= maxLength)
            {
                line += " " + word;
            }
            else
            {
                lines.push_back(line);
                line = word;
            }
        }

        lines.push_back(line);
    }

    if (lines.empty())
    {
        lines.push_back("");
    }

    return lines;
}

void addPDFLine(pdf_doc *pdf, const string &text, double fontSize,
                double &positionY)
{
    if (positionY < PAGE_BOTTOM + 20)
    {
        pdf_append_page(pdf);
        positionY = PAGE_TOP;
    }

    pdf_add_text(pdf, NULL, text.c_str(), fontSize,
                 LEFT_MARGIN, positionY, PDF_BLACK);
    positionY -= fontSize + 7;
}

void addPDFHeading(pdf_doc *pdf, const string &heading, double &positionY)
{
    positionY -= 4;
    addPDFLine(pdf, heading, 14, positionY);
    addPDFLine(pdf, "------------------------------------------------------------", 8, positionY);
}

void addPDFField(pdf_doc *pdf, const string &label, const string &value,
                 double &positionY)
{
    const vector<string> lines = wrapText(label + ": " + displayValue(value), MAX_LINE_LENGTH);

    for (size_t i = 0; i < lines.size(); ++i)
    {
        addPDFLine(pdf, lines[i], 10, positionY);
    }
}
}

void generatePatientPDF(const PatientData &patient,
                        const SymptomData &symptomData)
{
    struct pdf_info info = {};
    snprintf(info.creator, sizeof(info.creator), "MEDICODE");
    snprintf(info.title, sizeof(info.title), "Patient Summary");

    pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);

    if (pdf == NULL)
    {
        cout << "PDF creation failed." << endl;
        return;
    }

    pdf_set_font(pdf, "Helvetica");
    pdf_append_page(pdf);

    double positionY = PAGE_TOP;

    addPDFLine(pdf, "MEDICODE", 24, positionY);
    addPDFLine(pdf, "PATIENT SUMMARY", 16, positionY);

    addPDFHeading(pdf, "PATIENT INFORMATION", positionY);
    addPDFField(pdf, "Patient ID", patient.patientID, positionY);
    addPDFField(pdf, "Name", patient.name, positionY);
    addPDFField(pdf, "Age", patient.age, positionY);
    addPDFField(pdf, "Sex", patient.sex, positionY);
    addPDFField(pdf, "Address", patient.address, positionY);
    addPDFField(pdf, "Civil Status", patient.civilStatus, positionY);

    addPDFHeading(pdf, "HISTORY OF PRESENT ILLNESS", positionY);
    addPDFField(pdf, "History of Present Illness", patient.historyPresentIllness, positionY);

    addPDFHeading(pdf, "PAST MEDICAL HISTORY", positionY);
    addPDFField(pdf, "Operations", patient.operations, positionY);
    addPDFField(pdf, "Immunizations", patient.immunizations, positionY);
    addPDFField(pdf, "Allergies", patient.allergies, positionY);
    addPDFField(pdf, "Hospitalizations", patient.hospitalizations, positionY);
    addPDFField(pdf, "Maintenance Medications", patient.maintenanceMeds, positionY);
    addPDFField(pdf, "Others", patient.othersMedical, positionY);

    addPDFHeading(pdf, "FAMILY HISTORY", positionY);
    addPDFField(pdf, "Bronchial Asthma", patient.bronchialAsthma, positionY);
    addPDFField(pdf, "Diabetes Mellitus", patient.diabetesMellitus, positionY);
    addPDFField(pdf, "Hypertension", patient.hypertension, positionY);
    addPDFField(pdf, "Pulmonary Tuberculosis", patient.pulmonaryTuberculosis, positionY);
    addPDFField(pdf, "Others", patient.othersFamily, positionY);

    addPDFHeading(pdf, "SOCIAL, ENVIRONMENTAL, PERSONAL HISTORY", positionY);
    addPDFField(pdf, "Smoker", patient.smoker, positionY);
    addPDFField(pdf, "Alcoholic Beverage Drinker", patient.alcoholicBeverageDrinker, positionY);
    addPDFField(pdf, "Work/Environmental Hazards", patient.workEnvironmentalHazards, positionY);

    if (patient.sex == "Female")
    {
        addPDFHeading(pdf, "OB-GYNE HISTORY", positionY);
        addPDFField(pdf, "Menarche", patient.menarche, positionY);
        addPDFField(pdf, "Menstrual History", patient.menstrualHistory, positionY);
        addPDFField(pdf, "Gravida", patient.gravida, positionY);
        addPDFField(pdf, "Para", patient.para, positionY);
        addPDFField(pdf, "Last Menstrual Period", patient.lastMenstrualPeriod, positionY);
        addPDFField(pdf, "Menopause", patient.menopause, positionY);
        addPDFField(pdf, "Others", patient.othersOBGyne, positionY);
    }

    addPDFHeading(pdf, "SYMPTOM SUMMARY", positionY);
    if (symptomData.summaryCompleted)
    {
        addPDFField(pdf, "Duration", symptomData.duration, positionY);
        addPDFField(pdf, "Severity", symptomData.severity, positionY);
        addPDFField(pdf, "Impact on Activities", symptomData.impact, positionY);
        addPDFField(pdf, "Progression", symptomData.progression, positionY);
        addPDFField(pdf, "Other Symptoms", symptomData.symptoms, positionY);
        addPDFField(pdf, "Warning Signs", symptomData.warningSigns, positionY);
        addPDFField(pdf, "Medication/Treatment", symptomData.medications, positionY);
    }
    else
    {
        addPDFLine(pdf, "No symptom questionnaire has been completed.", 10, positionY);
    }

    const int result = pdf_save(pdf, "MEDICODE_Summary.pdf");
    pdf_destroy(pdf);

    if (result >= 0)
    {
        cout << "PDF generated successfully: MEDICODE_Summary.pdf" << endl;
    }
    else
    {
        cout << "PDF generation failed." << endl;
    }
}
