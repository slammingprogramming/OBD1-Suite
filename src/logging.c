// logging.c

#include "logging.h"
#include <stdio.h>
#include <unistd.h>

void log_raw_data(int serial_fd) {
    FILE *log_file = fopen("raw_data_log.txt", "w");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char buffer[256];
    ssize_t num_bytes;
    while ((num_bytes = read(serial_fd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, num_bytes, log_file);
    }

    fclose(log_file);
}