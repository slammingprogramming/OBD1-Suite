// connection.c

#include "connection.h"
#include "protocols.h"
#include "logging.h"
#include "communication_handler.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

// Initialize serial connection with given settings
int init_serial_connection(const char *port, int baud_rate) {
    int serial_fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serial_fd == -1) {
        perror("Failed to open serial port");
        return -1;
    }

    struct termios options;
    tcgetattr(serial_fd, &options);
    cfsetispeed(&options, baud_rate);
    cfsetospeed(&options, baud_rate);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    tcsetattr(serial_fd, TCSANOW, &options);

    return serial_fd;
}

// Attempt to connect with each protocol and detect success
Protocol *detect_protocol(int serial_fd) {
    for (int i = 0; i < NUM_PROTOCOLS; i++) {
        // Configure serial settings for the protocol
        struct termios options;
        tcgetattr(serial_fd, &options);
        cfsetispeed(&options, supported_protocols[i].baud_rate);
        cfsetospeed(&options, supported_protocols[i].baud_rate);
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= (supported_protocols[i].data_bits == 8 ? CS8 : CS7);
        options.c_cflag &= ~(PARENB | PARODD);
        options.c_cflag |= (supported_protocols[i].parity == 1 ? PARENB : 0);
        options.c_cflag &= ~(CSTOPB);
        options.c_cflag |= (supported_protocols[i].stop_bits == 2 ? CSTOPB : 0);
        tcsetattr(serial_fd, TCSANOW, &options);

        // Send initialization sequence
        if (write(serial_fd, supported_protocols[i].init_sequence, supported_protocols[i].sequence_length) == -1) {
            perror("Failed to write initialization sequence");
            continue;
        }

        // Check for response from protocol (can add specific read checks here)
        char buffer[256];
        ssize_t num_bytes = read(serial_fd, buffer, sizeof(buffer));
        if (num_bytes > 0) {
            printf("Connected with protocol: %s\n", supported_protocols[i].name);
            return &supported_protocols[i]; // Success
        }
    }

    // No protocol detected, log raw data
    fprintf(stderr, "No supported protocol detected. Logging raw data...\n");
    log_raw_data(serial_fd);
    return NULL;
}

// Connect to OBD system with detection and error handling
void connect_to_obd(const char *port) {
    int serial_fd = init_serial_connection(port, B9600);  // Default to 9600 for initial attempt
    if (serial_fd == -1) return;

    Protocol *protocol = detect_protocol(serial_fd);
    if (!protocol) {
        fprintf(stderr, "Error: No compatible OBD-I system found.\n");
        close(serial_fd);
        return;
    }

    CommunicationHandler *handler = init_communication_handler(serial_fd, protocol);
    if (!handler) {
        fprintf(stderr, "Error initializing communication handler.\n");
        close(serial_fd);
        return;
    }

    // Example command (replace with actual commands)
    char response[256];
    send_command(handler, "TEST_COMMAND", response, sizeof(response));
    printf("Response: %s\n", response);

    close_communication_handler(handler);
}