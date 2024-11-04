// communication_handler.c

#include "communication_handler.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Initialize communication handler with a protocol
CommunicationHandler *init_communication_handler(int serial_fd, Protocol *protocol) {
    CommunicationHandler *handler = malloc(sizeof(CommunicationHandler));
    if (!handler) return NULL;

    handler->serial_fd = serial_fd;
    handler->protocol = protocol;

    // Initialize the protocol by sending its init sequence
    if (write(serial_fd, protocol->init_sequence, protocol->sequence_length) == -1) {
        perror("Failed to initialize protocol communication");
        free(handler);
        return NULL;
    }

    return handler;
}

// Send a command and get response over the connected protocol
int send_command(CommunicationHandler *handler, const char *command, char *response, size_t response_size) {
    if (write(handler->serial_fd, command, strlen(command)) == -1) {
        perror("Failed to send command");
        return -1;
    }

    ssize_t bytes_read = read(handler->serial_fd, response, response_size);
    if (bytes_read < 0) {
        perror("Failed to read response");
        return -1;
    }

    response[bytes_read] = '\0';  // Null-terminate the response
    return bytes_read;
}

// Clean up communication handler resources
void close_communication_handler(CommunicationHandler *handler) {
    if (handler) {
        close(handler->serial_fd);
        free(handler);
    }
}