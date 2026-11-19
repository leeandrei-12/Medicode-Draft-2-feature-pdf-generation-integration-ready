# MEDICODE PDF Generation - Integration-Ready Snapshot

## What this folder represents

This is a source snapshot prepared by comparing the two supplied GitHub ZIP downloads:

- `Medicode-Draft-2-main.zip` was treated as the current `main` baseline.
- `Medicode-Draft-2-feature-pdf-generation.zip` was treated as the proposed PDF-generation feature.

GitHub ZIP downloads contain source files but do not contain the repository's `.git` directory, local branches, commit history, or merge base. This folder is therefore an integration-ready working-tree snapshot, **not a Git branch** and not a substitute for a normal Git merge.

## Integration choices made

The PDF feature was connected to the current `main` baseline while retaining the main snapshot's healthcare-facility module.

- Added `patientdata.h` so patient and symptom information can be shared between program modules.
- Added `pdfgenerator.cpp` and `pdfgenerator.h` and connected them to the main menu.
- Updated `patientpersonalinfo.cpp/.h` to store the collected profile in `PatientData`.
- Updated `generalquestions.cpp/.h` to store questionnaire answers in `SymptomData` and retain the existing summary, GP connection, health-guidance, back-to-menu, and exit choices.
- Updated `mainmenu.cpp/.h` to keep the main features and add `PRINT PATIENT SUMMARY` as option 3. The menu now stays active until the user exits.
- Updated `combination.cpp` to be the only application entry point.
- Updated `medicodebanner.cpp/.h` and `patientconsent.cpp/.h` so the banner and consent prompts are called once and can stop the program when the user does not proceed or consent.
- Kept `healthcarefacility.cpp/.h` from the supplied `main` ZIP instead of replacing it with the feature ZIP's placeholder doctor list.
- Reused the `PDFgen/` library already present in both ZIPs. The folder spelling is consistently `PDFgen` in source and build files.
- Added `build.bat`, updated the VS Code build task, and added `.gitignore` entries for generated build files and PDFs.
- Moved the standalone PDF-library test source to `tests/pdf_test.cpp` so its own `main()` cannot collide with MEDICODE's application `main()`.
- Removed precompiled `.exe` files and generated `.o`/PDF outputs from this source bundle. They should be rebuilt locally.

## Build and run on Windows

The project expects GCC and G++ to be available on `PATH` (for example, the MSYS2 UCRT64 toolchain).

From the project root in PowerShell:

```powershell
.\build.bat
```

After a successful build:

```powershell
.\MEDICODE.exe
```

The PDF is saved as `MEDICODE_Summary.pdf` in the program's current working directory. Generating another summary replaces the previous file with the same name.

## Important integration note

Do not copy this folder over an existing Git clone in a way that replaces or deletes its `.git` directory. To integrate it into the real GitHub repository, open a proper clone, create or switch to the intended feature branch, and copy/compare the source files from this snapshot. Review the resulting Git diff before committing or pushing.

## Validation performed

- Compiled the C PDF library with GCC.
- Compiled and linked the MEDICODE C++ sources with G++ into one executable.
- Ran a startup/consent/main-menu/exit check.
- Ran a patient-profile flow and confirmed the PDF was generated.
- Ran a symptom-questionnaire flow and confirmed the PDF was generated.
- Checked the generated PDF metadata and extracted text; it is an A4 PDF with multiple pages when the summary content requires it.

The build was validated with the available GCC/G++ toolchain in this environment. The Windows `build.bat` itself should still be run on the target Windows PC to confirm its local MSYS2 PATH setup.

## Existing behavior not redesigned here

The questionnaire's choices labelled `Back to Previous Question` are retained from the supplied code but are still recorded as answers rather than implementing true question navigation. This integration focuses on preserving the supplied questionnaire and wiring its collected data into PDF generation.
