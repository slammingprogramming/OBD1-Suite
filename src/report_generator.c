#include "report_generator.h"
#include "data_parser.h"
#include <stdio.h>

void generate_report(const DiagnosticCode *dtc_array, int dtc_count) {
    FILE *file = fopen("diagnostic_report.txt", "w");
    if (file) {
        fprintf(file, "Diagnostic Report\n");
        fprintf(file, "=================\n");
        for (int i = 0; i < dtc_count; i++) {
            fprintf(file, "Code: %s - %s\n", dtc_array[i].code, dtc_array[i].description);
        }
        fclose(file);
        printf("Report generated successfully.\n");
    } else {
        perror("Error creating report file");
    }
}