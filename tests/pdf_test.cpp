// Standalone PDF library test. Compile this separately; do not add it to the MEDICODE build.

#include <iostream>
#include <cstdio>
#include "../PDFgen/pdfgen.h"

using namespace std;

int main() {
    struct pdf_info info = {};

    snprintf(info.creator, sizeof(info.creator), "MEDICODE");
    snprintf(info.title, sizeof(info.title), "Patient Summary");

    pdf_doc *pdf = pdf_create(PDF_A4_WIDTH, PDF_A4_HEIGHT, &info);

    if (pdf == NULL) {
        cout << "PDF creation failed!";
        return 1;
    }

    pdf_set_font(pdf, "Helvetica");
    pdf_append_page(pdf);

    pdf_add_text(pdf, NULL, "MEDICODE", 24, 50, 780, PDF_BLACK);
    pdf_add_text(pdf, NULL, "PATIENT SUMMARY", 16, 50, 740, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Name: Juan Dela Cruz", 12, 50, 690, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Age: 25", 12, 50, 670, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Category: Physical Health", 12, 50, 650, PDF_BLACK);
    pdf_add_text(pdf, NULL, "Symptoms: Headache and fever", 12, 50, 630, PDF_BLACK);

    int result = pdf_save(pdf, "MEDICODE_Summary.pdf");

    pdf_destroy(pdf);

    if (result >= 0) {
        cout << "PDF generated successfully!";
    } else {
        cout << "PDF generation failed!";
    }

    return 0;
}
