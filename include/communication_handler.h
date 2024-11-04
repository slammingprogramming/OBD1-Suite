// communication_handler.h

#ifndef COMMUNICATION_HANDLER_H
#define COMMUNICATION_HANDLER_H

#include "protocols.h"

typedef struct {
    int serial_fd;
    Protocol *protocol;
} CommunicationHandler;

CommunicationHandler *init_communication_handler(int serial_fd, Protocol *protocol);
int send_command(CommunicationHandler *handler, const char *command, char *response, size_t response_size);
void close_communication_handler(CommunicationHandler *handler);

#endif // COMMUNICATION_HANDLER_H