#ifndef OBD1_INTERFACE_H
#define OBD1_INTERFACE_H

#include <stdio.h>

typedef struct {
    char code[6];
    char description[100];
} DiagnosticCode;

int init_obd_connection(const char *port);
void close_obd_connection(int fd);
void send_obd_command(int fd, const char *command);
char *read_obd_response(int fd);
int retrieve_dtc_codes(int fd, DiagnosticCode *dtc_array, int max_codes);
int clear_dtc_codes(int fd);
int retrieve_live_data(int fd);
int get_vin(int fd, char *vin_buffer, size_t buffer_len);

#endif // OBD1_INTERFACE_H