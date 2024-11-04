#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include "obd1_interface.h"

// Function to generate a diagnostic report based on DTC data
void generate_report(const DiagnosticCode *dtc_array, int dtc_count);

#endif // REPORT_GENERATOR_H