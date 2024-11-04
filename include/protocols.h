// protocols.h

#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include <stdint.h>

typedef struct {
    const char *name;
    int baud_rate;
    const char *init_sequence;
    int sequence_length;
    int data_bits;
    int stop_bits;
    int parity;
} Protocol;

// Define supported protocols
#define NUM_PROTOCOLS 3

static Protocol supported_protocols[NUM_PROTOCOLS] = {
    {"ALDL (GM)", 160, "\x12\x34", 2, 8, 1, 0},
    {"Ford MCU", 9600, "\x56\x78", 2, 8, 1, 0},
    {"Mazda M-M", 1200, "\xAB\xCD", 2, 8, 1, 0}
};

#endif // PROTOCOLS_H