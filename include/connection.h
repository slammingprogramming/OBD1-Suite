// connection.h

#ifndef CONNECTION_H
#define CONNECTION_H

int init_serial_connection(const char *port, int baud_rate);
int detect_protocol(int serial_fd);
void connect_to_obd(const char *port);

#endif // CONNECTION_H