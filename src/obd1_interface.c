#include "obd1_interface.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

int init_obd_connection(const char *port) {
    int fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Unable to open OBD port");
        return -1;
    }
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag |= CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &options);
    return fd;
}

void close_obd_connection(int fd) {
    close(fd);
}

void send_obd_command(int fd, const char *command) {
    write(fd, command, strlen(command));
    write(fd, "\r", 1);
}

char *read_obd_response(int fd) {
    static char buffer[256];
    int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Error reading OBD response");
        return NULL;
    }
    buffer[bytes_read] = '\0';
    return buffer;
}

int retrieve_dtc_codes(int fd, DiagnosticCode *dtc_array, int max_codes) {
    send_obd_command(fd, "03"); // Command for retrieving DTCs
    char *response = read_obd_response(fd);
    if (!response) return -1;

    // Parse the response for DTC codes and populate dtc_array...
    // Parsing logic goes here

    return 0;
}

int clear_dtc_codes(int fd) {
    send_obd_command(fd, "04"); // Clear DTC command
    return 0;
}

int retrieve_live_data(int fd) {
    send_obd_command(fd, "01 00"); // Command for live data
    return 0;
}

int get_vin(int fd, char *vin_buffer, size_t buffer_len) {
    send_obd_command(fd, "09 02");
    char *response = read_obd_response(fd);
    if (!response) return -1;
    strncpy(vin_buffer, response, buffer_len - 1);
    return 0;
}