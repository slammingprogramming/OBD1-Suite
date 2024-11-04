#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include "obd1_interface.h"

void parse_dtc_response(const char *response, DiagnosticCode *dtc_array, int *count);
void interpret_error_code(const DiagnosticCode *code);

#endif // DATA_PARSER_H