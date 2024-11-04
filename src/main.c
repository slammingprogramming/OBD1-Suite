// main.c

#include "connection.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <serial_port>\n", argv[0]);
        return 1;
    }

    connect_to_obd(argv[1]);
    return 0;
}