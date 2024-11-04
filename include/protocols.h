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

// Extended list of OBD-I protocols for different manufacturers and models
#define NUM_PROTOCOLS 12

static Protocol supported_protocols[NUM_PROTOCOLS] = {
    {"ALDL (GM 160 Baud)", 160, "\xF4\x57", 2, 8, 1, 0},
    {"ALDL (GM 8192 Baud)", 8192, "\xF4\x57", 2, 8, 1, 0},
    {"Ford MCU (Standard)", 9600, "\x56\x78", 2, 8, 1, 0},
    {"Ford MCU (Alt)", 10400, "\x12\x34", 2, 8, 1, 0},
    {"Mazda M-M", 1200, "\xAB\xCD", 2, 8, 1, 0},
    {"Toyota DLC (Standard)", 9600, "\x55\xAA", 2, 8, 1, 1},
    {"Honda OBD-I", 9600, "\x83\x01\x7C", 3, 8, 1, 0},
    {"Chrysler SCI (Slow)", 7812, "\xA0\xB0", 2, 8, 1, 0},
    {"Chrysler SCI (Fast)", 15625, "\xA0\xB0", 2, 8, 1, 0},
    {"Nissan Consult", 9600, "\xD1\xAA", 2, 8, 1, 0},
    {"BMW ADS", 9600, "\x42\x81", 2, 8, 1, 0},
    {"Volvo OBD-I", 4800, "\xA5\xA5", 2, 8, 1, 0}
};

#endif // PROTOCOLS_H